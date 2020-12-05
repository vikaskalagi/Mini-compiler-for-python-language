#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct symtable
{
    int line;
    //char type[10];
    char name[30];
    char value[50];
    int scope;
    int type_flag;
    struct symtable* next;
};
typedef struct symtable Node;


int checkTable(Node* head,char* name,int line,char* value,int scope,int type_flag)
{
    Node* temp = head;
    while(temp!=NULL){
        if(strcmp(name,(char*)temp->name)==0 && scope==temp->scope )
	{
	    strcpy(temp->value,value);
	    temp->line=line;
        temp->type_flag=type_flag;
            return 1;

	}
        temp=temp->next;
    }
    return -1;
}


Node* pushIntoTable(Node* head,int line,char* name,char* value,int scope,int type_flag)
{
    int validate = checkTable(head,name,line,value,scope,type_flag);
    Node* temp = head;
    int flag=0;
    if (validate == 1)
    {
        return head;
    }  
     
    

    Node* new = (Node*)malloc(sizeof(Node));
    new->line = line;
    
    strcpy((char*)new->name,name);
    strcpy((char*)new->value,value);
    new->scope=scope;
    new->next = head;
    new->type_flag=type_flag;
    head = new;
    return head;
}


void printTable(Node* head)
{

    if(head == NULL){ 
        return;
    }
    while(head!=NULL){
        if(head->type_flag==-1)
        printf("|\t%d\t|\t%s\t|\t%s\t|\t-\t|\n",head->line,(char*)head->name,(char*)head->value);
        else if(head->type_flag==1)
        printf("|\t%d\t|\t%s\t|\t%s\t|\tstring\t|\n",head->line,(char*)head->name,(char*)head->value);
        else if(head->type_flag==2)
        printf("|\t%d\t|\t%s\t|\t-\t|\tlist\t|\n",head->line,(char*)head->name);
        else if(head->type_flag==0)
        printf("|\t%d\t|\t%s\t|\t%s\t|\tnumeric\t|\n",head->line,(char*)head->name,(char*)head->value);
        head = head->next;
    }

}

char * search_symbol_table(Node* head,char *string)
{   char *a=malloc(sizeof(char)*10);
    //printf("sdfaf");
    if(head == NULL){ 
        a="0\0";
        //a[1]="\0";
        return a;
    }
    while(head!=NULL){
        if(strcmp((char*)head->name,string) == 0)
        {   printf("%s",head->value);
            strcpy(a,(char*)head->value);
            return a;
        }
        head=head->next;
    }
    a="0\0";
    return a;

}

int getValue(int value1, int value2, char* operator){
    if(strcmp(operator, ">") == 0) 
        return value1 > value2;
    else if(strcmp(operator, "<") == 0) 
        return value1 < value2;
    else if(strcmp(operator, ">=") == 0) 
        return value1 >= value2;
    else if(strcmp(operator, "<=") == 0)
        return value1 <= value2;
    else if(strcmp(operator, "==") == 0)
        return value1 == value2;        
    else 
        return value1 != value2;    
}
