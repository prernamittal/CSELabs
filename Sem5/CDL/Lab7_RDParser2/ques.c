#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LA.h"

FILE *fp;
struct token tk;

void program();
void declaration();
int datatype();
void id(struct token);
void assignstat(struct token);

void invalid(){
    printf("-----------------ERROR!----------------\n");
    exit(0);
}

void valid(){
    printf("----------------SUCCESS!---------------\n");
    exit(0);
}

void program(){
    token=LA(fp);
    if(strcmp(, "main")==0){

    }


}
