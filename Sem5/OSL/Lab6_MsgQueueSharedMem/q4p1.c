#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "header.h"


// function checks whether current player (process) won
int won(Table t)
{
	if (t.matrix[1] > 0) {
		if ((t.matrix[1] == t.matrix[2]) && (t.matrix[1] == t.matrix[3]))
			return 1;
		else
			if ((t.matrix[1] == t.matrix[4]) && (t.matrix[1] == t.matrix[7]))
			return 1;
			else
				if ((t.matrix[1] == t.matrix[5]) && (t.matrix[1] == t.matrix[9]))
				return 1;
	}
	if (t.matrix[9] > 0) {
		if ((t.matrix[9] == t.matrix[8]) && (t.matrix[9] == t.matrix[7]))
			return 1;
		else
			if ((t.matrix[9] == t.matrix[6]) && (t.matrix[9] == t.matrix[3]))
				return 1;
	}
	return 0;

}

//deletes shared memory
void removeshm(int shmid)
{
  	shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory deleted.\n");
}

//prints gameboard
void print_table(Table t)
{
	int i, j;
	printf("The board: \n");
	for (i=0; i < t.rows; i++) {
	    for (j=0; j < t.columns; j++) {
			printf("%d ",t.matrix[i * t.columns + j]);
	    }
		 printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	if( argc != 1 )
	{
		printf("Error: no parameter needed!\n");
		exit(0);
  	}
//for details, check header
	Table t;
	t.key = 100;
	t.rows = 3;
	t.columns = 3;

	t.matrix[10] = 0;

//connecting to shared memory
	int shmid = shmget(t.key, 9 * sizeof(int), IPC_CREAT | 0666);
	if (shmid == -1) {
			printf("Existing shared memory. \n");
		}
	else
		printf("Creating new shared memory \n");

	if ((t.matrix = shmat(shmid, NULL, 0)) == (void *) -1) {
			perror("Some error!");
			exit(1);
		}

	srand(getpid());

	while(1) {
//during even steps it's the turn of current player 
		if (t.matrix[10] % 2 == 0) {
			int pos = rand() % (9 - 1) + 1;
//player chooses a free field on the gameboard (field with value of zero) 
			 while (t.matrix[pos] != 0)
				 pos = rand() % (9 - 1) + 1;
			t.matrix[pos] = 1;
			t.matrix[10]++;
			printf("No. of current step: %d \n", t.matrix[10]);
			 print_table(t);
			if (won(t) == 1) {
				t.matrix[10] = 10;
				break;
			}
		}
		printf("\n\n");
		sleep(5);
		if (t.matrix[10] >= 9)
			break;
	}

	removeshm(100);
removeshm(shmid);
}