%{
#include<stdio.h>
#include<stdlib.h>
%}


%token integer id semicolon comma nextLine

%%
statement : declaration nextLine { printf("Valid declaration statement!\n"); exit(0);}
;
declaration : integer idList semicolon
;
idList: id |id comma idList 
;
%%

int yyerror(char *msg){
    printf("Invalid declaration statement!\n");
    exit(0);
}

void main (){
    printf("Enter the declaration statement:\n");
    yyparse();
}
