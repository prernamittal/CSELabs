%{
#include <stdio.h>
int scans = 0, prints = 0;
%}

%%
"scanf" {fputs("READ", yyout); scans += 1;}
"printf" {fputs("WRITE", yyout); prints += 1;}
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