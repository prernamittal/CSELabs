/*S -> UVW
U -> (S) | aSb | d
V -> aV | ε
W -> cW | ε*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[100];

void U();
void V();
void S();
void W();

void invalid(){
    printf("-----------------ERROR!----------------\n");
    exit(0);
}

void valid(){
    printf("----------------SUCCESS!---------------\n");
    exit(0);
}

void S(){
    U();
    V();
    W();
}

void W(){
    if(str[curr] == 'c'){
        curr++;
        W();
    }
}


void U(){
    if(str[curr] == '('){
        curr++;
        S();
        if(str[curr] == ')'){
        curr++;
        return;
        }
        else
        valid();
    }
    else if(str[curr] == 'a'){
        curr++;
        S();
        if(str[curr] == 'b'){
        curr++;
        return;
        }
        else
        valid();
    }
    else if(str[curr] == 'd'){
        curr++;
        return;
    }
    else
        invalid();
}

void V(){
    if(str[curr] == 'a'){
        curr++;
        V();
    }
}

int main(){
    printf("Enter String: ");
    scanf("%s", str);
    S();
    if(str[curr] == '$')
        valid();
    else
        invalid();
}