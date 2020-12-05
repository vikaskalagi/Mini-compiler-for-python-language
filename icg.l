%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    #include<string.h>
    extern int yylineno;
void store(char *s,int line);

FILE *yyin;
FILE *yyout;

char ident[30]="-";
char val[30]="-";
int scope=1;

char res[1024];
int line=0;


%}

%option yylineno
T_LETTER  [a-zA-Z\_][a-zA-Z\_0-9]*
T_DIGIT   [0-9]
T_ID  {T_LETTER}({T_LETTER}|{T_DIGIT})*
T_STRING    \"[^"\n]*\"
NEWLINE   [\n]
T_INDENT [\t]
T_ASSIGN ["="]
T_REL_OP ["<" | ">" | ">=" | "<=" ]
T_LT ["<"]
T_GT [">"]
T_GE [">="]
T_LE ["<="]
T_EEQ ["=="]
T_NEQ ["!="]
T_LIST_OP ["==" |  "!="  ]
T_star ['\*\*']
T_minus ['-']
T_space [" "]+
T_COMMENT (\'\'\')(.*\n)*.*(\'\'\')  
%%
\#(.*\n) {line++;}
{T_COMMENT}  {line++;}
{T_space} {strcat((char*)res,yytext);};

{NEWLINE} {line++;fprintf(yyout,"%d %s\n",line,(char*)res);strcpy((char*)res,"");return NEWLINE;}
\. {strcat((char*)res,yytext);return *yytext;}
{T_INDENT} {strcat((char*)res,yytext);return T_INDENT ;}
"+" return *yytext;
{T_minus} {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_minus;}
"\*" return *yytext;
"\/" return *yytext;
"\*\*" {strcpy(yylval.var,yytext);return T_star;}

"[" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return *yytext;}
"]" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return *yytext;}

[  ":" | ","] {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return *yytext;}
[()] {strcat((char*)res,yytext);return *yytext;}
{T_ASSIGN} {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_ASSIGN;}
"<"  {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LT;}
">"  {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_GT;}
">=" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_GE;}
"<=" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LE;}
"==" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_EEQ;}
"!=" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_NEQ;}
"not in" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LIST_OP;}
"is"     {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LIST_OP;}
"is not" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LIST_OP;}
"in" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_IN;}
"if" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_IF;}
"for" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_FOR;}
"int" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_INT;}
"split" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_SPLIT;}
"list" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_LIST;}
"input" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_INPUT;}
"range" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_RANGE;}
"print" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_PRINT;}
"else" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_ELSE;}
"elif" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_ELIF;}
"true" {strcat((char*)res,yytext); strcpy(yylval.var,yytext);return T_TRUE;}
"False" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_FALSE;}
"and" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_AND;}
"or" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_OR;}
"not" {strcat((char*)res,yytext);strcpy(yylval.var,yytext);return T_NOT;}

{T_ID} {strcat((char*)res,yytext);strcpy((char*)ident,yytext);strcpy(yylval.var,yytext);char t[sizeof(yytext)];strcpy(t,yytext);char *s = (char*)malloc(sizeof(yytext)) ; s = t ; store(s,yylineno); return T_ID;}
{T_STRING} {strcat((char*)res,yytext);strcpy((char*)val,yytext);strcpy(yylval.var,yytext);return T_STRING;}
{T_DIGIT}+ {strcat((char*)res,yytext);strcpy((char*)val,yytext);strcpy(yylval.var,yytext);return T_DIGIT;}

.  {yytext[0];}



%%

void store(char *s,int line)
{



//FILE *fp= fopen("id.txt","a+");

//char t[50];
//while(fgets(t,50,fp)!=NULL)
//{


//if(strstr(t,s))
//{
//return;
//}
//}
//fprintf(fp,"%s,%d\n",s,yylineno);
//fclose(fp);*/
return;

}