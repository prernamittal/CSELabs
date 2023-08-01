#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *arg[]){
	int sfd, sfd2, i=0, k=0, p=0;
	char ch[100], ch2[100], chr;

	if(argc!=3){
		printf("\ninsuff args\n");
	}
	if((sfd=open(arg[1],O_RDONLY))==-1){
		printf("\nerror: file not found");
		exit(1);
	}
	while((read(sfd,&chr,1))>0){
		if(chr!='\n'){
			ch[i++] = chr;
		} else{
			k++;
			p++;
			ch[i] = '\0';
			i=0;
			printf("\nline %d: %s",p,ch);
			if(k==20){
				fgetc(stdin);
				k=0;
			}
		}
	}
	close(sfd);

	if((sfd2 = open(arg[2],O_RDONLY)) == -1){
		printf("File not found!\n");
		exit(2);
	}
	p=0;
	while((read(sfd2, &chr, 1)) > 0){
		if(chr != '\n'){
			ch2[i++] = chr;
		} else{
			k++;
			p++;
			ch[i] = '\0';
			i=0;
			printf("\nline %d: %s",p,ch2);
			if(k == 20){
				fgetc(stdin);
				k=0;
			}
		}
	}
	exit(0);
}
