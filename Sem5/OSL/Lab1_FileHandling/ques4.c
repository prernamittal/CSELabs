#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *arg[]){
	char c;
	int in,nread,out;
	char buffer[128];

	if(argc!=3){
		printf("\ninsuff args\n");
	}
	in=open(arg[1],O_RDWR);
	out=open(arg[2],O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	if( in==-1 || out==-1){
		printf("\nerror: file not found");
		exit(1);
	}
	while(read(in,&c,1) == 1){
		write(out,&c,1);
	}
	printf("copied\n");
	exit(0);
}
