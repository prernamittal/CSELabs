%{
#include <stdio.h>
int characters = 0, lines = 1, blanks = 0, words = 1;
%}

%%
\n {lines += 1; characters += 1; words += 1;}
\t {blanks += 4; characters += 1; words += 1;}
" \n" {lines += 1; characters += 2; words += 1;}
" " {blanks += 1; characters += 1; words += 1;}
. characters += 1;
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
    printf("\nwords: %d\ncharacters: %d\nlines: %d\nblanks: %d\n", words, characters, lines, blanks);
}