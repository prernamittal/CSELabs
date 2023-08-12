#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fa, *fb;
    char c = 0;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *dirInc = "include", *dirDef = "define";
	fa = fopen("inputFile.c","r");
	if(fa == NULL){
		printf("Cannot open file!\n");
		exit(0);
	}
	fb = fopen("outputFile.c","w");
    while(c != EOF){
		c = fgetc(fa);
		if(c == '#'){
			while(c != ' '){
				c = fgetc(fa);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if(strstr(buffer, dirInc) != NULL || strstr(buffer, dirDef) != NULL){
				while(c != '\n'){
					c = fgetc(fa);
				}
			}
			else{
				fputc('#', fb);
				for(int j=0;j<i;j++){
					fputc(buffer[j], fb);
				}
				while(c != '\n'){
					c = fgetc(fa);
					fputc(c, fb);
				}
			}
			i = 0;
			buffer[0] = '\0';
		}
    }
	fclose(fa);
	fclose(fb);
    printf("preprocessor directives removed\n");
	return 0;
}