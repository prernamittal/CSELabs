#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printToken(char* buf, int row, int col){
    printf("<%s,%d,%d>\n",buf, row, col);
}

int main(){
    int row=0, col=0;
    char lexeme[10];
    char c,buf[100];
    char *dirInc = "include", *dirDef = "define";
    FILE *fp=fopen("testFile.c","r");
    c = fgetc(fp);

    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }

    while(c!=EOF) {
        col++;
        if(c=='\n') {
            row++;
            col=0;
        }
        int i=0;
        buf[0]='\0';

        // ---------------------------remove pre-processor directives-------------------------
        if(c == '#'){
			while(c != ' '){
				c = fgetc(fp);
				buf[i++] = c;
			}
			buf[i] = '\0';
			if(strstr(buf, dirInc) != NULL || strstr(buf, dirDef) != NULL){
				while(c != '\n'){
					c = fgetc(fp);
				}
			}
			i = 0;
			buf[0] = '\0';
		}

        // --------------------------operator identification----------------------------------
        if(c=='=') {
            buf[i++]=c;
            c = fgetc(fp);
            if(c=='=') {
                buf[i++]=c;
                buf[i]='\0';
                printToken(buf, row, col);
                i = 0;
			    buf[0] = '\0';
            }
            else {
                buf[i]='\0';
                printToken(buf, row, col);
                i = 0;
			    buf[0] = '\0';
            }
        }
        else if(c=='<'||c=='>'||c=='!') {
            buf[i++]=c;
            c = fgetc(fp);
            if(c=='='){
                buf[i++]=c;
            }
            buf[i]='\0';
            printToken(buf, row, col);
            i = 0;
            buf[0] = '\0';
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'){
            buf[i++]=c;
            c = fgetc(fp);
            if(c=='='||c=='+'||c=='-') {
                buf[i++]=c;
                buf[i]='\0';
                printToken(buf, row, col);
                i = 0;
			    buf[0] = '\0';
            }
            buf[i]='\0';
            printToken(buf, row, col);
            i = 0;
            buf[0] = '\0';
        }
        else if(c=='&'||c=='|'||c=='!'||c=='('||c==')'||c==';'||c=='{'||c=='}'||c=='['||c==']'||c==','){
            buf[i++]=c;
            c = fgetc(fp);
            buf[i]='\0';
            printToken(buf, row, col);
            i = 0;
            buf[0] = '\0';
        }

        // --------------------------string literals----------------------------------------
        if(c=='"'||(c >= 97 && c <= 122) || (c >= 65 && c <= 90)){
            while(c!='\0'){
                buf[i++]=c;
                c = fgetc(fp);
                printf("%d", i);
                buf[i]='\0';
            }
            printToken("id", row, col);
            i = 0;
            buf[0] = '\0';
        }
        else if((c >= '0' && c <= '9')){
            while(c!='\0'){
                buf[i++]=c;
                c = fgetc(fp);
                buf[i]='\0';
            }
            printToken("num", row, col);
            i = 0;
            buf[0] = '\0';
        }
        //---------------------------------------------------------------------------------
        else {
                buf[i]='\0';
            }
        c = fgetc(fp);
    }
}
