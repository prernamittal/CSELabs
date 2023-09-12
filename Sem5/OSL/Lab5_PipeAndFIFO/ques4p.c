#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>

#define FIFO_NAME "./fifo"
#define BUFFER_SIZE PIPE_BUF

int main(){
	int pipe_fd,res, n=0;
	int open_mode1 = O_WRONLY, open_mode2 = O_RDONLY;
	char buffer[BUFFER_SIZE + 1];
	if (access(FIFO_NAME, F_OK) == -1) {
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0) {
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	printf("Communicating with consumer...\n");
	while (1){
		pipe_fd = open(FIFO_NAME, open_mode2);
		printf("\nDemand by consumer: ");
		res = read(pipe_fd, buffer, BUFFER_SIZE);
		if (strstr(buffer, "exit") != NULL)
			break;
		printf("%s\n", buffer);
		close(pipe_fd);

		pipe_fd = open(FIFO_NAME, open_mode1);
		printf("\nRestock Amount: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		res = write(pipe_fd, buffer, BUFFER_SIZE);
		close(pipe_fd);
	}
	close(pipe_fd);
	printf("Process %d finished.\n", getpid());
	exit(EXIT_SUCCESS);
}