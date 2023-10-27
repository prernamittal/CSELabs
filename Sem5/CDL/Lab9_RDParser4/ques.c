#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LexAn.c"

FILE *fp;
struct token tk;

void program();
void declaration();
int data_type();
int assign_stat();
void identifier_list1();
void identifier_list2();
void identifier_list3();
void statement_list();
int statement();
void expn();
void eprime();
void simple_expn();
void seprime();
void term();
void tprime();
void factor();
int relop();
int addop();
int mulop();
int decision_stat();
int looping_stat();
void dprime();

void invalid(){
    printf("-----------------ERROR!----------------\n");
    exit(0);
}

void valid(){
    printf("----------------SUCCESS!---------------\n");
    exit(0);
}

void program(){
    tk=getNextToken(fp);
    if(strcmp(tk.lexeme, "main")==0){
        tk=getNextToken(fp);
        if(strcmp(tk.lexeme,"(")==0){
            tk=getNextToken(fp);
            if(strcmp(tk.lexeme,")")==0){
                tk=getNextToken(fp);
                if(strcmp(tk.lexeme,"{")==0){
                    tk=getNextToken(fp);
                    if(strcmp(tk.lexeme,"}")==0){
                        return;
                    }
                    else
                        invalid();
                }
                else
                    invalid();
            }
            else
                invalid();
        }
        else
            invalid();
    }
    else
        invalid();
}

void declarations(){
	if(data_type()){
		identifier_list1();
		if(strcmp(tk.type,";")==0){
			tk=getNextToken(fp);
			declarations();
		}
		else
			invalid();
	}
}

int data_type(){
	if(strcmp(tk.type,"int")==0 ){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"char")==0 ){
		tk=getNextToken(fp);
		return 1;
	}
	else
		return 0;
}

int assign_stat(){
	if(strcmp(tk.type,"id")==0){
		    tk=getNextToken(fp);
		if(strcmp(tk.type,"=")==0){
            tk=getNextToken(fp);
			expn();
			return 1;
		}
		else
            invalid();
	}
	else
		return 0;
}

void identifier_list1(){
	if(strcmp(tk.type,"id")==0){
		tk=getNextToken(fp);
		identifier_list1();
	}
	else
		invalid();
}

void identifier_list2(){
    tk=getNextToken(fp);
	if(strcmp(tk.type,",")==0){
		tk=getNextToken(fp);
		identifier_list1();
	}
	else if(strcmp(tk.type,"[")==0){
		tk=getNextToken(fp);
		if(strcmp(tk.type,"num")==0){
			tk=getNextToken(fp);
            if(strcmp(tk.type,"]")==0){
				tk=getNextToken(fp);
				identifier_list3();
			}
			else
				invalid();
		}
		else
			invalid();
	}
}

void identifier_list3(){
	if(strcmp(tk.type,",")==0){
		tk=getNextToken(fp);
		identifier_list1();
	}
}

void statement_list(){
	if(statement()){
		statement_list();
	}
}

int statement(){
    if (assign_stat()){
        if (strcmp(tk.type, ";") == 0){
            return 1;
        }
        else
            invalid(";");
    }
    else if (decision_stat()){
    }
    else if (looping_stat()){
    }
    else
        return 0;
}

void expn(){
	simple_expn();
	eprime();
}

void eprime(){
	if(relop()){
		simple_expn();
	}
}

void simple_expn(){
	term();
	seprime();
}

void seprime(){
	if(addop()){
		term();
		seprime();
	}
}

void term(){
	factor();
	tprime();
}

void tprime(){
	if(mulop()){
		factor();
		tprime();
	}
}

void factor(){
	if(strcmp(tk.type,"id")==0)
		tk=getNextToken(fp);
	else if(strcmp(tk.type,"num")==0)
		tk=getNextToken(fp);
	else
		invalid("id | num");
}

int relop(){
	if(strcmp(tk.type,"==")==0){
		tk=getNextToken(fp);
		return 1;
    }
	else if(strcmp(tk.type,"!=")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"<=")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,">=")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,">")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"<")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else
		return 0;
}

int addop(){
	if(strcmp(tk.type,"+")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"-")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else
		return 0;
}

int mulop(){
	if(strcmp(tk.type,"*")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"/")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else if(strcmp(tk.type,"%")==0){
		tk=getNextToken(fp);
		return 1;
	}
	else
		return 0;
}

int decision_stat(){
    if (strcmp(tk.type, "if") == 0){
        if (strcmp(tk.type, "(") == 0){
            expn();
            if (strcmp(tk.type, ")") == 0){
                if (strcmp(tk.type, "{") == 0){
                    statement_list();
                    if (strcmp(tk.type, "}") == 0){
                        dprime();
                    }
                    else
                        invalid("}");
                }
                else
                    invalid("{");
            }
            else
                invalid(")");
            return 1;
        }
        else
            invalid("(");
    }
    else
        return 0;
}

int looping_stat(){
    if (strcmp(tk.type, "while") == 0){
        if (strcmp(tk.type, "(") == 0){
            expn();
            if (strcmp(tk.type, ")") == 0){
                if (strcmp(tk.type, "{") == 0){
                    statement_list();
                    if (strcmp(tk.type, "}") == 0)
                        dprime();
                    else
                        invalid("}");
                }
                else
                    invalid("{");
            }
            else
                invalid(")");
            return 1;
        }
        else
            invalid("(");
    }
    else if (strcmp(tk.type, "for") == 0){
        if (strcmp(tk.type, "(") == 0){
            assign_stat();
            if (strcmp(tk.type, ";") == 0){
                expn();
                if (strcmp(tk.type, ";") == 0){        
                    assign_stat();
                    if (strcmp(tk.type, ")") == 0){
                        if (strcmp(tk.type, "{") == 0){
                            statement_list();
                            if (strcmp(tk.type, "}") == 0)
                                dprime();
                            else
                                invalid("}");
                        }
                        else
                            invalid("{");
                    }
                    else
                        invalid(")");
                }
                else
                    invalid(";");
            }
            else
                invalid(";");
        }
        else
            invalid("(");
    }
    else
        return 0;
}

void dprime(){
    if (strcmp(tk.type, "else") == 0){
        if (strcmp(tk.type, "{") == 0){
            statement_list();
            if (strcmp(tk.type, "}") == 0){
            }
            else
                invalid("}");
        }
        else
            invalid("{");
    }
}

int main(){
    fp = fopen("input.c", "r");
    if (fp == NULL){
        printf("Error!\n");
        return 0;
    }
    program();
    valid();
}