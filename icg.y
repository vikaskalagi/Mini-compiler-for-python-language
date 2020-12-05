%{ 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "symboltable.c" 
int flag=0; 
int indent=0;
int k;
extern int yylineno;
int fun_indent(int i);
void fun_cond(int i);
int yywrap();
extern int curLn;
extern int curPos;
extern FILE *yyin;
int type_flag=0;
extern FILE *yyout;
extern int line;
extern char ident[30];
extern char val[30];
extern int scope;
FILE *outfile;



	// ------------------------- Used for AST -------------------------
	

typedef struct node{
	char value[50];
	char expr_result[15];
	char reg_name[15];
	struct node *left;
	struct node *right;
}node;
//typedef struct node node;
	node* make_node(char *,node *,node *);
	void print_tree_pre(node *);
	void print_tree_in(node *);
	void print_tree_post(node *);
// ------------------------- Used for ICG --------------------------
	struct quad
	{
		char op[5];
		char arg1[10];
		char arg2[10];
		char result[10];
		int scope;
		char block[10];
		int indi;
		char actual_result[10];
	}QUAD[500];
	struct quad sub_QUAD[500];
	int sub_Index = 0;
	int sub_rIndex=0;
	//char* store=malloc(sizeof(char)*20);
	//char *store=malloc(sizeof(char)*10);
	int folding=0;
	void sub_add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi);
	char * search_in_quad(char* op,char *arg1,char* arg2);
	int number;
	extern int scope_count;
	int Index = 0;
	int rIndex=0; 
	int offset = 0;
	void add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi,char *actual_re);
	char for_k_liye[10];
	// extra implementations
	struct stack 
	{
		char label[10][10];
		int top;
	}stk;
	void push(char *label);	
	void pop();
	char* get_top();
	void eprint(struct quad);
	void eprint2(struct quad);
//--------------------------------------------------------------------------------

Node* head=NULL;
int yylex();
void yyerror(char *s);
%} 
%union 
{
struct node *np;
	char var[10];
}
%token <var> T_ASSIGN T_REL_OP T_LOGIC T_KEY T_ID T_STRING T_DIGIT T_IF T_FOR T_INT T_SPLIT T_LIST T_INPUT T_RANGE T_PRINT T_ELSE T_ELIF T_TRUE T_FALSE T_AND T_OR T_NOT T_LIST_OP T_IN T_star T_minus  T_LT  T_GT  T_GE T_LE  T_EEQ T_NEQ
%token  NEWLINE T_INDENT T_space
%left '+' '-'

%left '*' '/' '%'

%left '(' ')'

%type <np> PHASE_START START START_FOR_INDENT INTERMEDIATE SIMPLE_STMT A B UI GI ASSIGN E T F Q VAR L M REL_OP LIST_OP COND AND_STMT NOT_STMT N REL_EXP FOR_STMT IF_STMT INNER_IF C SUITE INNER_SUITE ELIF_STMT TARGET 

%% 
PHASE_START: {push("main");}START {	//printf("asdf");
						
						printf("\n %s \n",get_top());
						$$ = make_node("PROGRAM", $2, NULL);
						printf("\nPreorder Traversal \n"); 
						print_tree_pre($$);
						printf("\nInorder Traversal \n"); 
						print_tree_in($$); 
						printf("\nPostorder Traversal \n");
						print_tree_post($$);
						pop();
					 }
					 ;

START:  ASSIGN NEWLINE START {$$ = make_node("", $1, $3);}|   FOR_STMT  START {$$ = make_node("", $1, $2);} | IF_STMT START {$$ = make_node("", $1, $2);}| SIMPLE_STMT NEWLINE START {$$ = make_node("", $1, $3);} |error {$$=NULL;}| NEWLINE {k=0;} START {$$ = make_node("", $3, NULL);}|{$$=NULL;};

START_FOR_INDENT:  INDENT_GRAMMER ASSIGN NEWLINE	{k=0;} START_FOR_INDENT {$$ = make_node("", $2, $5);}| INDENT_GRAMMER  FOR_STMT NEWLINE {k=0;} START_FOR_INDENT {$$ = make_node("", $2, $5);} | INDENT_GRAMMER INNER_IF NEWLINE  {k=0;} START_FOR_INDENT {$$ = make_node("", $2, $5);}| INDENT_GRAMMER SIMPLE_STMT NEWLINE {k=0;} START_FOR_INDENT {$$ = make_node("", $2, $5);}|{$$=NULL;};

INTERMEDIATE:INDENT_GRAMMER ASSIGN NEWLINE	{k=0;printf("ay a %s\n",get_top());} START_FOR_INDENT {$$ = make_node("", $2, $5);}| INDENT_GRAMMER  FOR_STMT NEWLINE {k=0;} START_FOR_INDENT {$$ = make_node("FOR_STATEMENT", $2, $5);} | INDENT_GRAMMER INNER_IF NEWLINE {k=0;} START_FOR_INDENT {$$ = make_node("IF_STATEMENT", $2, $5);}| INDENT_GRAMMER SIMPLE_STMT NEWLINE {k=0;} START_FOR_INDENT {$$ = make_node("", $2, $5);}; 

INDENT_GRAMMER: T_INDENT {fun_cond(fun_indent(0));} GOP {int uy=indent-k;printf("art %d %d\n",indent,k);while(uy>0){pop();uy-=1;}indent=k;};
GOP:T_INDENT {fun_cond(fun_indent(0));}  GOP| ;

SIMPLE_STMT : T_INT'('A')' {$$ = make_node("INT", $3, NULL);}| T_LIST'('B')' {$$ = make_node("LIST", $3, NULL);}| T_LIST '('A')' {$$ = make_node("LIST", $3, NULL);}| T_PRINT'(' UI ')' {$$ = make_node("PRINT", $3, NULL);}| A {$$=$1;}| B{$$=$1;};
A : T_INPUT '('GI')' {$$ = make_node("INPUT", $3, NULL);}; 
B : T_INPUT'('GI')' '.' T_SPLIT'('')' {$$ = make_node("INPUT_SPLIT", $3, NULL);};
UI : M {$$=$1;}| {$$=NULL;};
GI : T_STRING {$$=make_node($1, NULL, NULL);}|{$$=NULL;};

ASSIGN : T_ID T_ASSIGN E {head=pushIntoTable(head,line,(char*)$1,(char*)$3->expr_result,scope,type_flag);strcpy(val,"-");strcpy(ident,"-");	$$=make_node("=", make_node($1,NULL,NULL), $3);add_quadruple("=",$3->reg_name,"",$1,0,0,$3->expr_result);sub_add_quadruple("=",$3->reg_name,"",$1,0,0);}| T_ID T_ASSIGN SIMPLE_STMT {head=pushIntoTable(head,line,(char*)$1,(char*)$3->expr_result,scope,type_flag);strcpy(val,"-");strcpy(ident,"-");$$=make_node("=", make_node($1,NULL,NULL), $3);	}

E : E '+' T {$$ = make_node("+",$1,$3);
     			sprintf($$->expr_result, "%d",(atoi($1->expr_result) + atoi($3->expr_result)));char store[100];strcpy(store,search_in_quad("+",$1->reg_name,$3->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",$$->reg_name,1,0);}else{sub_add_quadruple("+",$1->reg_name,$3->reg_name,$$->reg_name,1,0);}add_quadruple("+",$1->reg_name,$3->reg_name,$$->reg_name,1,0,$$->expr_result);}| E T_minus T {$$ = make_node("-",$1,$3);
     			sprintf($$->expr_result, "%d",(atoi($1->expr_result) - atoi($3->expr_result)));char store[100];strcpy(store,search_in_quad("-",$1->reg_name,$3->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",$$->reg_name,1,0);}else{sub_add_quadruple("-",$1->reg_name,$3->reg_name,$$->reg_name,1,0);}add_quadruple("-",$1->reg_name,$3->reg_name,$$->reg_name,1,0,$$->expr_result);}| T {$$=$1;};
T : T '*' F {$$ = make_node("*",$1,$3);
     			sprintf($$->expr_result, "%d",(atoi($1->expr_result) * atoi($3->expr_result)));char store[100];strcpy(store,search_in_quad("*",$1->reg_name,$3->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",$$->reg_name,1,0);}else{sub_add_quadruple("*",$1->reg_name,$3->reg_name,$$->reg_name,1,0);}add_quadruple("*",$1->reg_name,$3->reg_name,$$->reg_name,1,0,$$->expr_result);}| T'/'F {$$ = make_node("/",$1,$3);
     			sprintf($$->expr_result, "%d",(atoi($1->expr_result) / atoi($3->expr_result)));char store[100];strcpy(store,search_in_quad("/",$1->reg_name,$3->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",$$->reg_name,1,0);}else{sub_add_quadruple("/",$1->reg_name,$3->reg_name,$$->reg_name,1,0);}add_quadruple("/",$1->reg_name,$3->reg_name,$$->reg_name,1,0,$$->expr_result);}| F {$$=$1;};
F : Q T_star F {$$ = make_node("**",$1,$3);
     			sprintf($$->expr_result, "%d",(atoi($1->expr_result) ^ atoi($3->expr_result)));char store[100];strcpy(store,search_in_quad("**",$1->reg_name,$3->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",$$->reg_name,1,0);}else{sub_add_quadruple("**",$1->reg_name,$3->reg_name,$$->reg_name,1,0);}add_quadruple("**",$1->reg_name,$3->reg_name,$$->reg_name,1,0,$$->expr_result);}| Q {$$=$1;};
Q : L {type_flag=2;$$=$1;}| '('E')' {$$=$2;}| VAR {$$=$1;};
VAR : T_ID  {type_flag=-1;$$=make_node($1,NULL,NULL);sprintf($$->expr_result,"%d",	(atoi(search_symbol_table(head,$1))));
     			
     			strcpy($$->reg_name,$1);}| T_DIGIT {type_flag=0;$$=make_node($1,NULL,NULL);strcpy($$->expr_result,$1);strcpy($$->reg_name,$1);} | T_STRING {type_flag=1;$$=make_node($1,NULL,NULL);strcpy($$->expr_result,$1);strcpy($$->reg_name,$1);};

L : '[' M ']' {$$=make_node("LIST",$2,NULL);} | '[' ']' {$$=make_node("LIST_EMPTY",NULL,NULL);};
M : Q ',' M {$$=make_node("",$1,$3);}| Q{$$=$1;};

REL_OP : T_LT {$$=make_node($1,NULL,NULL);}| T_GT {$$=make_node($1,NULL,NULL);}| T_GE{$$=make_node($1,NULL,NULL);}| T_LE {$$=make_node($1,NULL,NULL);}| LIST_OP{$$=$1;};
LIST_OP : T_EEQ{$$=make_node($1,NULL,NULL);}|T_NEQ{$$=make_node($1,NULL,NULL);};


COND :COND T_OR AND_STMT {$$ = make_node($2,$1,$3);sprintf($$->expr_result,"%d",(atoi($1->expr_result) || atoi($3->expr_result)));sub_add_quadruple($2,$1->reg_name,$3->reg_name,$$->reg_name,1,1);add_quadruple($2,$1->reg_name,$3->reg_name,$$->reg_name,1,1,"");} | AND_STMT{$$=$1;};

AND_STMT : AND_STMT T_AND NOT_STMT {$$ = make_node($2,$1,$3); sprintf($$->expr_result,"%d",(atoi($1->expr_result) && atoi($3->expr_result)));sub_add_quadruple($2,$1->reg_name,$3->reg_name,$$->reg_name,1,1);add_quadruple($2,$1->reg_name,$3->reg_name,$$->reg_name,1,1,"");}| NOT_STMT{$$=$1;};

NOT_STMT : T_NOT NOT_STMT {$$ = make_node($1,$2,NULL); sprintf($$->expr_result,"%d",(!atoi($2->expr_result)));sub_add_quadruple($1,$2->reg_name,"",$$->reg_name,1,1);add_quadruple($1,$2->reg_name,"",$$->reg_name,1,1,"");}| N{$$=$1;};

N : '('COND')' {$$=$2;} | REL_EXP {$$=$1;} | T_TRUE {$$ = make_node($1,NULL,NULL); sprintf($$->expr_result,"%d",(1));strcpy($$->reg_name,"1");sub_add_quadruple($1,"","",$$->reg_name,1,1);add_quadruple($1,"","",$$->reg_name,1,1,"");}| T_FALSE{$$ = make_node($1,NULL,NULL); sprintf($$->expr_result,"%d",(0));strcpy($$->reg_name,"0");sub_add_quadruple($1,"","",$$->reg_name,1,1);add_quadruple($1,"","",$$->reg_name,1,1,"");};

REL_EXP : VAR REL_OP VAR{$$ = make_node($2->value,$1,$3); sprintf($$->expr_result,"%d",(getValue(atoi($1->expr_result),atoi($3->expr_result),$2->value)));strcpy($$->reg_name,$$->expr_result);sub_add_quadruple($2->value,$1->reg_name,$3->reg_name,$$->reg_name,1,1);add_quadruple($2->value,$1->reg_name,$3->reg_name,$$->reg_name,1,1,"");} | L LIST_OP L {$$ = make_node($2->value,$1,$3); sprintf($$->expr_result,"%d",(0));strcpy($$->reg_name,$$->expr_result);sub_add_quadruple($2->value,"LIST","LIST","",0,1);add_quadruple($2->value,"LIST","LIST","",0,1,"");}| VAR LIST_OP L {$$ = make_node($2->value,$1,$3);sprintf($$->expr_result,"%d",(0));strcpy($$->reg_name,$$->expr_result);sub_add_quadruple($2->value,$1->reg_name,"LIST","",0,1);add_quadruple($2->value,$1->reg_name,"LIST","",0,1,"");}|
                      L LIST_OP VAR{$$ = make_node($2->value,$1,$3);sprintf($$->expr_result,"%d",(0));strcpy($$->reg_name,$$->expr_result);sub_add_quadruple($2->value,"LIST",$3->reg_name,"",0,1);add_quadruple($2->value,"LIST",$3->reg_name,"",0,1,"");};



INNER_SUITE :  {k=0;indent++;} INTERMEDIATE {fun_cond(fun_indent(1));$$ = $2;} ;
INNER_IF:T_IF { push("if"); offset++; }'(' COND ')' ':' NEWLINE INNER_SUITE {offset--; } ELIF_STMT {$$ = make_node("IF",$4,make_node("",$8,$10));};
SUITE : NEWLINE {k=0;indent++;} INTERMEDIATE {fun_cond(fun_indent(1));$$ = $3;} ;
IF_STMT  : T_IF { push("if"); offset++; } '(' COND ')' ':' SUITE {offset--;} ELIF_STMT {$$ = make_node("IF",$4,make_node("",$7,$9));};
ELIF_STMT : T_ELIF { push("elif"); offset++; }'(' COND ')' ':' SUITE  {offset--; } ELIF_STMT {$$ = make_node("ELIF",$4,make_node("",$7,$9));} | T_ELSE { push("else"); } ':' SUITE  {$$ = make_node("ELSE",NULL,$4);}|{$$=NULL;}; 

FOR_STMT : T_FOR { push("for"); offset++; }   T_ID  T_IN  TARGET {if($5->right==NULL){sub_add_quadruple("=","0","",$3,0,0);add_quadruple("=","0","",$3,0,0,"");sub_add_quadruple("<",$3,$5->left->value,$5->reg_name,1,1);add_quadruple("<",$3,$5->left->value,$5->reg_name,1,1,"");strcpy(for_k_liye,"1");}else if($5->right->left==NULL){sub_add_quadruple("=",$5->left->value,"",$3,0,0);add_quadruple("=",$5->left->value,"",$3,0,0,"");sub_add_quadruple("<",$3,$5->right->value,$5->reg_name,1,1);add_quadruple("<",$3,$5->right->value,$5->reg_name,1,1,"");strcpy(for_k_liye,"1");}else{sub_add_quadruple("=",$5->left->value,"",$3,0,0);add_quadruple("=",$5->left->value,"",$3,0,0,"");sub_add_quadruple("<",$3,$5->right->left->value,$5->reg_name,1,1);add_quadruple("<",$3,$5->right->left->value,$5->reg_name,1,1,"");strcpy(for_k_liye,$5->right->right->value);}}':' SUITE {$$ = make_node("FOR",make_node("COND",make_node($3,NULL,NULL),$5),$8);push("for");offset++;sub_add_quadruple("+",$3,for_k_liye,$3,0,2);add_quadruple("+",$3,for_k_liye,$3,0,2,"");pop(); offset-=2;};
TARGET : T_RANGE'('C')' {$$=make_node("range",$3,NULL);}| T_RANGE'('C',' C')' {$$=make_node("range",$3,$5);}| T_RANGE'('C','C','C')' {$$=make_node("range",$3,make_node("",$5,$7));}| T_ID {$$=make_node($1,NULL,NULL);sprintf($$->expr_result,"%d",(atoi(search_symbol_table(head,$1))));
     			
     			strcpy($$->reg_name,$1); }| L {$$=$1;};

C:T_ID{$$=make_node($1,NULL,NULL);sprintf($$->expr_result,"%d",	(atoi(search_symbol_table(head,$1))));
     			
     			strcpy($$->reg_name,$1);}|T_DIGIT{$$=make_node($1,NULL,NULL);strcpy($$->expr_result,$1);strcpy($$->reg_name,$1);};
%% 
node *make_node(char *value, node *left, node *right) 
{
	node *new_node = malloc(sizeof(node));
	strcpy(new_node->value, value);	
	new_node -> left = left;
	new_node -> right = right;
	return new_node;
}

void print_tree_pre(node *root)
{
	if (root == NULL)
		return;
	printf("%s ", root->value);
	print_tree_pre(root->left);	
	print_tree_pre(root->right);	
}

void print_tree_in(node *root)
{
	if (root == NULL)
		return;
	print_tree_in(root->left);
	printf("%s ", root->value);
	print_tree_in(root->right);
}

void print_tree_post(node *root)
{
	if (root == NULL)
		return;
	print_tree_post(root->left);	
	print_tree_post(root->right);
	printf("%s ", root->value);
}
//--------------------sub_expression--------------------------------------
void sub_add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi)
{	 
	strcpy(sub_QUAD[sub_Index].op,op);
	
	strcpy(sub_QUAD[sub_Index].arg1,arg1);
	strcpy(sub_QUAD[sub_Index].arg2,arg2);
	sub_QUAD[sub_Index].indi=indi;
	if(option == 0)
	{
		strcpy(sub_QUAD[sub_Index].result,result);
	}
	else
	{
		sprintf(sub_QUAD[sub_Index].result,"r%d",sub_rIndex++);
		strcpy(result,sub_QUAD[sub_Index].result); 
	}	
	//printf("aer %s\n",get_top());	
	strcpy(sub_QUAD[sub_Index].block,get_top());
	//QUAD[Index++].scope = scope_count + offset;
	//if(strcmp(QUAD[Index].block,"for")==0)
	//printf("asdf %d %d %s %s\n",indent,offset,QUAD[Index].arg1,QUAD[Index].op);
	sub_QUAD[sub_Index++].scope =indent+offset;//done by me
}

// ----------------------------- ICG -------------------------------------
void add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi,char *actual_re)
{	 
	strcpy(QUAD[Index].op,op);
	
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	QUAD[Index].indi=indi;
	if(option == 0)
	{
		strcpy(QUAD[Index].result,result);
	}
	else
	{
		sprintf(QUAD[Index].result,"r%d",rIndex++);
		strcpy(result,QUAD[Index].result); 
	}	
	strcpy(QUAD[Index].actual_result,actual_re);
	//printf("aer %s\n",get_top());	
	strcpy(QUAD[Index].block,get_top());
	//QUAD[Index++].scope = scope_count + offset;
	//if(strcmp(QUAD[Index].block,"for")==0)
	//printf("asdf %d %d %s %s\n",indent,offset,QUAD[Index].arg1,QUAD[Index].op);
	QUAD[Index++].scope =indent+offset;//done by me
}

void print_3addr_code()
{
	printf("\t\t\t\t Quadruples \t\t\t\t\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t","pos","op","arg1","arg2","result");
	printf("\n\t------------------------------------------------------------------------");
	for(int i=0;i<Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n\n\n");
	
	// printing in proper 3 address code
	int label_no = 1;
	int add_label = 0;
	int label_stk[20];
	int ltop = -1;

	char gotos[20][10];
	int fstates = 0;
	struct fsteps{
		int start_index;
		int step;
	}fsteps[1000];
	int ftop = -1;
	int estart = 1;
	int infor = 0;
	int for_k[1000];
	int for_k_value=0;
	int for_go[1000];
	int for_go_value=0;
	for(int i=0; i<Index; i++)
	{	//printf("inner %s %d %d %s \n",QUAD[i].block,QUAD[i].scope,QUAD[i-1].scope,QUAD[i].op);
		// statements in same scope or within blocks
		if(i != 0 && QUAD[i].scope >= QUAD[i-1].scope){
			
			//if(QUAD[i-1].scope != QUAD[i].scope)
			//if( strcmp(QUAD[i].block,"elif") != 0 && (strcmp(QUAD[i-1].block,"while") == 0 || (strcmp(QUAD[i-1].block,"for") == 0) || (strcmp(QUAD[i-1].block,"if") == 0)))
			//{
			//printf("L%d:\n",label_stk[ltop]);
			//}

			if(strcmp(QUAD[i].block,"main") == 0)
			{
				eprint2(QUAD[i]);
			}
			if(strcmp(QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",QUAD[i].result);
				//if(QUAD[i-1].scope != QUAD[i].scope)
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
				else
				{	
					eprint2(QUAD[i]);	
				}
			}
			else if(strcmp(QUAD[i].block,"elif") == 0)
			{	/*
				if(estart == 1 && QUAD[i-1].scope != QUAD[i].scope)
				{
					fprintf(outfile,"goto L%d qwe \n",label_stk[ltop]+1);
					fprintf(outfile,"L%d: qwee\n",label_stk[ltop]);
					
					label_stk[ltop]++;
					
					estart = 0;
				}*/
				eprint2(QUAD[i]);
				//printf("as %d %d \n",QUAD[i+1].indi,QUAD[i].indi);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					//eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
			}
			if(strcmp(QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					fprintf(outfile,"goto L%d\n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					label_stk[ltop]++;
					estart = 0;
				//}
				eprint2(QUAD[i]);
			}
			if(strcmp(QUAD[i].block,"while") == 0)
			{
				if(QUAD[i-1].scope != QUAD[i].scope)
				{
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_no++,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
					label_stk[++ltop] = label_no;
					label_no++;
				}
				else
				{
					eprint2(QUAD[i]);
				}
			}
			if(strcmp(QUAD[i].block,"for") == 0)
			{//printf("%d %d %d \n ",QUAD[i].indi, QUAD[i-1].scope ,QUAD[i].scope);	
			if(QUAD[i].indi==1 )
				//if(QUAD[i-1].scope != QUAD[i].scope )
				{//printf("er %d %d \n",QUAD[i-2].scope , QUAD[i].scope);	
				if((i>=2 && QUAD[i-2].scope < QUAD[i].scope))
					{

					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_stk[ltop]+1,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no+1);
						for_k[for_k_value++]=label_stk[ltop]+1;
						for_go[for_go_value++]=label_no+1;
						label_stk[++ltop] = label_no+1;
						label_no+=2;
						
					}
				
					else //if(QUAD[i].indi==1 && i>=2 && QUAD[i-2].scope < QUAD[i].scope)
					{
						
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_stk[ltop--],QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
					for_k[for_k_value++]=label_stk[ltop+1];
					for_go[for_go_value++]=label_no;
					label_stk[++ltop] = label_no;
					label_no++;

					}
				}
				else
				{
					eprint2(QUAD[i]);
					if(QUAD[i].indi==2 )
				{
					fprintf(outfile,"goto L%d\n",for_k[--for_k_value]);
					fprintf(outfile,"L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
					
					
				}
				//printf("%d %d asd\n",i+1,Index);
				
			}
		} // if they come out of block
		else
		{	//printf("\n %s %s %d asd\n",QUAD[i].result,QUAD[i].block,QUAD[i].scope >= QUAD[i-1].scope);
			if(i == 0) 
			{ 
				fprintf(outfile,"%s:\n",QUAD[i].block);
				//in_block[++top] = 0;
				eprint2(QUAD[i]);

			}
			else
			{
			//printf("\n %s %s %d %d %d asd\n",QUAD[i].result,QUAD[i].block,QUAD[i].scope >= QUAD[i-1].scope,QUAD[i].scope , QUAD[i-1].scope);



				if(strcmp(QUAD[i-1].block,"while") == 0){ fprintf(outfile,"goto L%d\n",label_stk[ltop]-1);fprintf(outfile,"L%d:\n",label_stk[ltop--]);}
				else if(strcmp(QUAD[i].block,"for") == 0)
				{
					if(QUAD[i].indi==1)
				//if(QUAD[i-1].scope != QUAD[i].scope )
				{
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_no++,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
				}
				else
				{
					eprint2(QUAD[i]);
						if(QUAD[i].indi==2 )
				{
					fprintf(outfile,"goto L%d\n",for_k[--for_k_value]);
					fprintf(outfile,"L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
				}
				}
				else if(strcmp(QUAD[i].block,"if") == 0)
			{	//fprintf(outfile,"\n%s \n",QUAD[i].result);
				//if(QUAD[i-1].scope != QUAD[i].scope)
				fprintf(outfile,"L%d:\n",label_stk[ltop--]);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
				else
				{	
					eprint2(QUAD[i]);	
				}
			}
				else if(strcmp(QUAD[i].block,"elif") == 0  && QUAD[i].indi==1)
				{	//fprintf(outfile,"asr %d %d \n",QUAD[i].scope,QUAD[i-1].scope);
					fprintf(outfile,"goto L%d \n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					
					label_stk[ltop]++;
					eprint2(QUAD[i]);
				//printf("as %d %d \n",QUAD[i+1].indi,QUAD[i].indi);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					//eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
					
				}
				else if(strcmp(QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					fprintf(outfile,"goto L%d\n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					label_stk[++ltop]=label_no;
					label_no++;
					estart = 0;
				//}
				eprint2(QUAD[i]);
			}
				else{
				//printf("L%d: erter\n",label_stk[ltop--]);
				eprint2(QUAD[i]);
				}

				
			}
			//eprint2(QUAD[i]);
			estart = 1;
		}
		
	}
	
	fprintf(outfile,"L%d:\n",label_stk[ltop--]);
	fprintf(outfile,"\n\n");	

}

void sub_print_3addr_code()
{
	printf("\t\t\t\t sub_QUADruples \t\t\t\t\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t","pos","op","arg1","arg2","result");
	printf("\n\t------------------------------------------------------------------------");
	for(int i=0;i<sub_Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t", i,sub_QUAD[i].op, sub_QUAD[i].arg1,sub_QUAD[i].arg2,sub_QUAD[i].result);
	}
	printf("\n\n\n\n");
	
	// printing in proper 3 address code
	int label_no = 1;
	int add_label = 0;
	int label_stk[20];
	int ltop = -1;

	char gotos[20][10];
	int fstates = 0;
	struct fsteps{
		int start_sub_Index;
		int step;
	}fsteps[1000];
	int ftop = -1;
	int estart = 1;
	int infor = 0;
	int for_k[1000];
	int for_k_value=0;
	int for_go[1000];
	int for_go_value=0;
	for(int i=0; i<sub_Index; i++)
	{	//printf("inner %s %d %d %s \n",sub_QUAD[i].block,sub_QUAD[i].scope,sub_QUAD[i-1].scope,sub_QUAD[i].op);
		// statements in same scope or within blocks
		if(i != 0 && sub_QUAD[i].scope >= sub_QUAD[i-1].scope){
			
			//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
			//if( strcmp(sub_QUAD[i].block,"elif") != 0 && (strcmp(sub_QUAD[i-1].block,"while") == 0 || (strcmp(sub_QUAD[i-1].block,"for") == 0) || (strcmp(sub_QUAD[i-1].block,"if") == 0)))
			//{
			//printf("L%d:\n",label_stk[ltop]);
			//}

			if(strcmp(sub_QUAD[i].block,"main") == 0)
			{
				eprint(sub_QUAD[i]);
			}
			if(strcmp(sub_QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",sub_QUAD[i].result);
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("ifFalse %s goto L%d\n",sub_QUAD[i].result,label_no++);
				}
				else
				{	
					eprint(sub_QUAD[i]);	
				}
			}
			else if(strcmp(sub_QUAD[i].block,"elif") == 0)
			{	/*
				if(estart == 1 && sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				{
					printf("goto L%d qwe \n",label_stk[ltop]+1);
					printf("L%d: qwee\n",label_stk[ltop]);
					
					label_stk[ltop]++;
					
					estart = 0;
				}*/
				eprint(sub_QUAD[i]);
				//printf("as %d %d \n",sub_QUAD[i+1].indi,sub_QUAD[i].indi);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					//eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("ifFalse %s goto L%d\n",sub_QUAD[i].result,label_no++);
				}
			}
			if(strcmp(sub_QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					printf("goto L%d\n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					label_stk[ltop]++;
					estart = 0;
				//}
				eprint(sub_QUAD[i]);
			}
			if(strcmp(sub_QUAD[i].block,"while") == 0)
			{
				if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				{
					printf("L%d:\nifFalse %s%s%s goto L%d\n",label_no++,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
					label_stk[++ltop] = label_no;
					label_no++;
				}
				else
				{
					eprint(sub_QUAD[i]);
				}
			}
			if(strcmp(sub_QUAD[i].block,"for") == 0)
			{//printf("%d %d %d \n ",sub_QUAD[i].indi, sub_QUAD[i-1].scope ,sub_QUAD[i].scope);	
			if(sub_QUAD[i].indi==1 )
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope )
				{//printf("er %d %d \n",sub_QUAD[i-2].scope , sub_QUAD[i].scope);	
				if((i>=2 && sub_QUAD[i-2].scope < sub_QUAD[i].scope))
					{

					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_stk[ltop]+1,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no+1);
						for_k[for_k_value++]=label_stk[ltop]+1;
						for_go[for_go_value++]=label_no+1;
						label_stk[++ltop] = label_no+1;
						label_no+=2;
						
					}
				
					else //if(sub_QUAD[i].indi==1 && i>=2 && sub_QUAD[i-2].scope < sub_QUAD[i].scope)
					{
						
					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_stk[ltop--],sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
					for_k[for_k_value++]=label_stk[ltop+1];
					for_go[for_go_value++]=label_no;
					label_stk[++ltop] = label_no;
					label_no++;

					}
				}
				else
				{
					eprint(sub_QUAD[i]);
					if(sub_QUAD[i].indi==2 )
				{
					printf("goto L%d\n",for_k[--for_k_value]);
					printf("L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
					
					
				}
				//printf("%d %d asd\n",i+1,sub_Index);
				
			}
		} // if they come out of block
		else
		{	//printf("\n %s %s %d asd\n",sub_QUAD[i].result,sub_QUAD[i].block,sub_QUAD[i].scope >= sub_QUAD[i-1].scope);
			if(i == 0) 
			{ 
				printf("%s:\n",sub_QUAD[i].block);
				//in_block[++top] = 0;
				eprint(sub_QUAD[i]);

			}
			else
			{
			//printf("\n %s %s %d %d %d asd\n",sub_QUAD[i].result,sub_QUAD[i].block,sub_QUAD[i].scope >= sub_QUAD[i-1].scope,sub_QUAD[i].scope , sub_QUAD[i-1].scope);



				if(strcmp(sub_QUAD[i-1].block,"while") == 0){ printf("goto L%d\n",label_stk[ltop]-1);printf("L%d:\n",label_stk[ltop--]);}
				else if(strcmp(sub_QUAD[i].block,"for") == 0)
				{
					if(sub_QUAD[i].indi==1)
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope )
				{
					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_no++,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
				}
				else
				{
					eprint(sub_QUAD[i]);
						if(sub_QUAD[i].indi==2 )
				{
					printf("goto L%d\n",for_k[--for_k_value]);
					printf("L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
				}
				}
				else if(strcmp(sub_QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",sub_QUAD[i].result);
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				printf("L%d:\n",label_stk[ltop--]);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("if(!(%s)) goto L%d\n",sub_QUAD[i].result,label_no++);
				}
				else
				{	
					eprint(sub_QUAD[i]);	
				}
			}
				else if(strcmp(sub_QUAD[i].block,"elif") == 0  && sub_QUAD[i].indi==1)
				{	//printf("asr %d %d \n",sub_QUAD[i].scope,sub_QUAD[i-1].scope);
					printf("goto L%d \n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					
					label_stk[ltop]++;
					eprint(sub_QUAD[i]);
				//printf("as %d %d \n",sub_QUAD[i+1].indi,sub_QUAD[i].indi);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					//eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("if(!(%s)) goto L%d\n",sub_QUAD[i].result,label_no++);
				}
					
				}
				else if(strcmp(sub_QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					printf("goto L%d\n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					label_stk[++ltop]=label_no;
					label_no++;
					estart = 0;
				//}
				eprint(sub_QUAD[i]);
			}
				else{
				//printf("L%d: erter\n",label_stk[ltop--]);
				eprint(sub_QUAD[i]);
				}

				
			}
			//eprint(sub_QUAD[i]);
			estart = 1;
		}
		
	}
	
	printf("L%d:\n",label_stk[ltop--]);
	printf("\n\n");	

}
char * search_in_quad(char* op,char *arg1,char* arg2)
{ char *a=malloc(sizeof(char)*10);
	//static char *a="";
	for(int i=0; i<Index; i++)
	{
		if(strcmp(QUAD[i].op,op)==0 && strcmp(QUAD[i].arg1,arg1)==0 && strcmp(QUAD[i].arg2,arg2)==0)
		{
			strcpy(a,(char*)QUAD[i].result);
			return a;
		}
	}
	a="0\0";
    return a;
	
}
void eprint(struct quad quad)
{
	if(folding==1 && strcmp(quad.actual_result,"")!=0 && strcmp(quad.block,"main")==0)
	{
		printf("%s = %s\n", quad.result,quad.actual_result);
		return;
	}

	if(strcmp(quad.op,"=") == 0)
	{
		printf("%s %s %s\n", quad.result,quad.op,quad.arg1);
		return;
	}
	//if(strcmp(quad.block,"if") == 0 || strcmp(quad.block,"elif") == 0)
	//{
		//printf("%s %s %s A ", quad.arg1, quad.op, quad.arg2);
	//	printf("%s %s %s %s %s %s %d\n",quad.result, "=", quad.arg1, quad.op, quad.arg2,quad.block,quad.scope);
	//	return;
	//}
	printf("%s %s %s %s %s \n",quad.result, "=", quad.arg1, quad.op, quad.arg2);
}

void eprint2(struct quad quad)
{
	if(folding==1 && strcmp(quad.actual_result,"")!=0 && strcmp(quad.block,"main")==0)
	{	//printf(" %s in\n",quad.result);
		if(quad.result[0]=='r' && quad.result[1]>='0' && quad.result[1]<='9')
		{
			//printf("fdf \n");
		}
		else
		fprintf(outfile,"%s = %s\n", quad.result,quad.actual_result);
		return;
	}

	if(strcmp(quad.op,"=") == 0)
	{
		fprintf(outfile,"%s %s %s\n", quad.result,quad.op,quad.arg1);
		return;
	}
	//if(strcmp(quad.block,"if") == 0 || strcmp(quad.block,"elif") == 0)
	//{
		//printf("%s %s %s A ", quad.arg1, quad.op, quad.arg2);
	//	printf("%s %s %s %s %s %s %d\n",quad.result, "=", quad.arg1, quad.op, quad.arg2,quad.block,quad.scope);
	//	return;
	//}
	fprintf(outfile,"%s %s %s %s %s \n",quad.result, "=", quad.arg1, quad.op, quad.arg2);
}

void push(char *label)
{
	strcpy(stk.label[++stk.top],label);
}

void pop()
{
	stk.top--;
}

char* get_top()
{
	return stk.label[stk.top];
}

void main(int argc,char *argv[]) 
{ 
FILE *fp2=fopen("input1.py","r");
outfile = fopen("output_file.txt", "w");
if(!fp2)
{
	printf("unable to open");
	exit(0);
}
yyin=fp2;

FILE *fp1=fopen("out.py","w");
if(!fp1)
{
	printf("unable to open");
	exit(0);
}
yyout=fp1;
yyparse(); 
if(flag==0) {
printf("Valid\n\n"); 
}
printf("SYMBOL TABLE\n");
	printf("\tLINE\t\tID\t\tVALUE\t\tType\n");

	printTable(head);
	// print_3addr_code();
	sub_print_3addr_code();
	folding=1;
	print_3addr_code();
}

void yyerror(char *s) 
{ 
//printf("\n Invalid\n\n"); 
fprintf(stderr, " line : %s  %d\n", s,line);

flag=1; 
} 

int fun_indent(int i)
{
	if(i==0){
	k++;

	if(k>indent){
	
	return 0;
	}
	}
	else{
	int uy=indent-k;
	while(uy>0){pop();uy-=1;}
	indent=k;
	}
	return 1;
}
 
void fun_cond(int i)
{
	if(i==0)
	{
	yyerror("invalid indentation"); 
	}
}


int yywrap()

{

return 1;

}
