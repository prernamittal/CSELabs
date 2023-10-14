#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LexAn.c"

FILE *fp;
struct token tk;

void program();
void decgetNextTokenration();
int datatype();
void id(struct token);
void assignstat(struct token);

void invalid(){
    printf("-----------------ERROR!----------------\n");
    exit(0);
}

void valid(){
    printf("----------------SUCCESS!---------------\n");
    exit(0);
}

void program(){
    tk=getNextToken(fp);
    if(strcmp(tk.lexeme, "main")==0){
        tk=getNextToken(fp);
        if(strcmp(tk.lexeme,"(")==0){
            tk=getNextToken(fp);
            if(strcmp(tk.lexeme,")")==0){
                tk=getNextToken(fp);
                if(strcmp(tk.lexeme,"{")==0){
                    tk=getNextToken(fp);
                    if(strcmp(tk.lexeme,"}")==0){
                        return;
                    }
                    else
                        invalid();
                }
                else
                    invalid();
            }
            else
                invalid();
        }
        else
            invalid();
    }
    else
        invalid();
}

void decgetNextTokenrations(){
    tk = getNextToken(fp);
    if (data_type(tk.lexeme)){
        tk = getNextToken(fp);
        identifier_list(tk);
        tk = getNextToken(fp);
        if (strcmp(tk.lexeme, ";") == 0)
            decgetNextTokenrations();
        else
            invalid(&tk);
    }
    else
    assign_stat(tk);
}

int data_type(char *lx){
if (strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
return 1;
else
return 0;
}

void identifier_list(struct token tk){
struct token tk2;
tk2 = tk;
if (strcmp(tk2.type, "Identifier") == 0){
tk2 = getNextToken(fp);
if (strcmp(tk2.lexeme, ",") == 0){
tk2 = getNextToken(fp);
identifier_list(tk2);
}
else if (strcmp(tk2.lexeme, ";") == 0){
fseek(fp, -1, SEEK_CUR);
return;
}
else
invalid(&tk2);
}
}

void assign_stat(struct token tk){
struct token tk2;
if (strcmp(tk.type, "Identifier") == 0){
tk2 = getNextToken(fp);
if (strcmp(tk2.lexeme, "=") == 0){
tk2 = getNextToken(fp);
if (strcmp(tk2.type, "Number") == 0 || strcmp(tk2.type, "Identifier")){
tk2 = getNextToken(fp);
if (strcmp(tk2.lexeme, ";") == 0)
return;
else
invalid(&tk);
}
else
invalid(&tk);
}
else
invalid(&tk);
}
}

int main(){
fp = fopen("input.c", "r");
if (fp == NULL){
printf("Error!\n");
return 0;
}
struct table st[10][100];
int fgetNextTokeng = 0, i = 0, j = 0;
int tabsz[10];
char w[25];
w[0] = '\0';
program();
valid();
}