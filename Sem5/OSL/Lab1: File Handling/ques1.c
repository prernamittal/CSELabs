#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *arg[]){
	int sfd,i=0,k=0;
	char ch[100],chr;
	if(argc!=3){
		printf("\ninsuff args\n");

	exit(1);
	}
	if((sfd=open(arg[2], O_RDONLY))==-1){
		printf("\nerror: file not found");
		exit(1);
	}
	while(read(sfd,&chr,sizeof(char))>0){
		if(chr!='\n'){
			ch[i]=chr;
			i++;
		}
		else{
			k++;
			ch[i]='\0';
			i=0;
			if(strstr(ch,arg[1])!=NULL)
				printf("\nline %d: %s", k, ch);
		}
	}
	printf("\n");
	close(sfd);
	return 0;
}

