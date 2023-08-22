#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	char *message;
	int n;
	printf("\nfork program starting\n");
	pid = fork();
	switch(pid) {
	case -1:
		perror("\nfork failed");
		exit(1);
	case 0:
		printf("\nThis is the child: %d ", getpid());
		n = 5;
		break;
	default:
		printf("\nThis is the parent: %d \n",getpid());
		n = 3;
		break;
	}
	exit(0);
}