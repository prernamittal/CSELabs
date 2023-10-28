%{
#include <stdio.h>
int vowels=0, consonent=0;
%}

%%
[aAeEiIoOuU] vowels+=1;
[a-zA-Z] consonent+=1;
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text");
    yylex();
    printf("\vowels: %d\consonants: %d\n", vowels, consonent);
}