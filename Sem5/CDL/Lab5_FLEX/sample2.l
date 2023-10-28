%{ 
#include<stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* printf(" Identifier");
%%

int yywrap() {
    return 1;
}

int main(){
    char stat[20];
    printf("Enter the valid C statement");
    scanf("%s",stat);
}