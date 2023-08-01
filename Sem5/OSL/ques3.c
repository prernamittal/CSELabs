#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
	int a = 15;
	float b = 5.05;
	char c = 'P';
	char s[] = "Hello World";
	printf("a=%d\n b=%f\n c=%c\n s=%s\n Hexadecimal a=%x\n",a,b,c,s,a);
	errno = ENOENT;
	printf("Error: %m\n");
}
