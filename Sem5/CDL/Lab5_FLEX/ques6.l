%{
#include <stdio.h>
%}

%%
"//"[ \ta-zA-z0-9_.]+\n fputs(yytext, yyout);
"/*"[ \t\na-zA-z0-9_.]+"*/" fputs(yytext, yyout);
[A-Z] {for(int i = 0; yytext[i] != '\0'; i++) fputc((yytext[i]) + 32, yyout);}
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