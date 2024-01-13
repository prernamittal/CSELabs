#include "mpi.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank,size;
	char input[20];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank==0){
		printf("Enter a string in master process:");
		scanf("%s",input);
		MPI_Ssend(input,20,MPI_CHAR,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"I have sent %s from process 0\n",input);
		fflush(stdout);
		MPI_Recv(input,20,MPI_CHAR,1,2,MPI_COMM_WORLD,&status);

		fprintf(stdout,"I have received %s in process 0\n",input);
		fflush(stdout);

	}
	else{
		MPI_Recv(input,20,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"I have received %s in process 1\n",input);
		fflush(stdout);

		for(int i=0; i<21; i++){
			if(isupper(input[i]))
				input[i] = tolower(input[i]);
			else 
				input[i] = toupper(input[i]);
		}
		MPI_Ssend(input,20,MPI_CHAR,0,2,MPI_COMM_WORLD);
		fprintf(stdout,"I have sent %s from process 1\n",input);
		fflush(stdout);

	}
	MPI_Finalize();
	return 0;
}