%{
#include <stdio.h>
int pInt = 0, nInt = 0, pFloat = 0, nFloat = 0;
%}

%%
"-"[0-9]+\.[0-9]+ nFloat += 1;
[0-9]+\.[0-9]+ pFloat += 1;
"-"[0-9]+ nInt += 1;
[0-9]+ pInt += 1;
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
    printf("positive integers: %d\nnegative integers: %d\npositive floating number: %d\nnegative floating number: %d\n", pInt, nInt, pFloat, nFloat);
}

