%{
#include "ques1.tab.h"
%}

%%
int {return integer;}
; {return semicolon;}
, {return comma;}
[a-zA-Z][a-zA-Z0-9_]* {return id; }
\n {return nextLine;}
%%

int yywrap(){return 1;}