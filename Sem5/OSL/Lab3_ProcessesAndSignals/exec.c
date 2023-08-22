
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
		execlp("/home/oslab/Desktop/210905328/CSELabs/Sem5/OSL/printID", "printID", NULL);
		break;
	default:
		wait (NULL);
		printf ("Child Complete");
		exit(0);
	}
}