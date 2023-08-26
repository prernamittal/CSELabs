#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void relational(char c, char buf[10], FILE *fp){
    int i=0;
    buf[0]='\0';
    if(c=='=') {
        buf[i++]=c;
        c = fgetc(fp);
        if(c=='=') {
            buf[i++]=c;
            buf[i]='\0';
            printf("\n Relational operator : %s\n",buf);
        }
        else {
            buf[i]='\0';
            printf("\n Assignment operator: %s\n",buf);
        }
    }
    else {
        if(c=='<'||c=='>'||c=='!') {
            buf[i++]=c;
            c = fgetc(fp);
            if(c=='='){
                buf[i++]=c;
            }
            buf[i]='\0';
            printf("\n Relational operator : %s\n",buf);
        }
        else {
            buf[i]='\0';
        }
    }
    c = fgetc(fp);
}

int main(){
    char c,buf[10];
    FILE *fp=fopen("testFile.c","r");
    c = fgetc(fp);
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    while(c!=EOF) {
        relational(c,buf,fp);

    }
}