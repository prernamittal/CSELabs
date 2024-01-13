#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank,size;
	int x[30];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;

	int buffsize=100;
	int buff[buffsize];
	MPI_Buffer_attach(buff, buffsize);

	if(rank==0){
		printf("Enter %d elements in master process:", size);
		for(int i=0; i<size; i++){
			scanf("%d", &x[i]);
		}
		for(int i=1; i<size; i++){
			MPI_Bsend(&x[i],1,MPI_INT,i,i,MPI_COMM_WORLD);
			fprintf(stdout,"\nI have sent %d from process %d\n",x[i], rank);
		}
		fflush(stdout);
	}
	else{
		int recv;
		MPI_Recv(&recv,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
		if(rank % 2==0){
			fprintf(stdout,"\nSquare of number %d : %d from process %d",recv, recv*recv, rank);
		}
		else
			fprintf(stdout,"\nCube of number %d : %d from process %d",recv, recv*recv*recv, rank);
	}
	MPI_Buffer_detach(buff, &buffsize);
	MPI_Finalize();
	return 0;
}