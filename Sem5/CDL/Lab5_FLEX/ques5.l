%{
#include <stdio.h>
%}

%%
[0-9]+ {int n = atoi(yytext); char hex[20]; sprintf(hex, "%X", n); fputs(hex, yyout);}
%%

int yywrap() {
    return 1;
}

int main() {
    char *filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    yyin = fopen(filename, "r");
    yylex();
    fclose(yyin);
}