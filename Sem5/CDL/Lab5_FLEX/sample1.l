%{
int chars = 0;
int words = 0;
int lines = 0;
%}

%%
[a-zA-Z]+ { words++; chars += strlen(yytext); }
\n { chars++; lines++; }
. { chars++; }
%%

int yywrap(){
    return 1;
}

main(int argc, char **argv){
    yylex();
    printf("lines: %d\twords: %d\tchars: %d\n", lines, words, chars); 
}
