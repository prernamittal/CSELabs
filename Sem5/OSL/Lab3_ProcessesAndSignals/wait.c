#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	int status;
	pid_t pid;
	pid = fork();
	switch(pid) {
	case -1:
		perror("fork failed");
		exit(1);
	case 0:
		printf("This is the child");
		break;
	default:
		wait(&status);
		printf("\n I'm the parent!");
		printf("\n Child returned: %d\n", status);
		break;
	}
}