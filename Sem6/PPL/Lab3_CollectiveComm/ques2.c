#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank,size,N,M,A[10],B[10], c, i;
	float avg=0;
    float * D = (float *) malloc(size * sizeof(float));

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0){
		N=size;
		printf("Enter value of M: \n");
		scanf("%d", &M);
		for(i=0; i<M*N; i++)
		scanf("%d",&A[i]);
	}

	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(A,M,MPI_INT,B,M,MPI_INT,0,MPI_COMM_WORLD);

	for (int i = 0; i < M; i++)
        avg += (float) B[i] / M;
    	
	fprintf(stdout,"Avg %f in process %d\n",avg,rank);
	fflush(stdout);

	MPI_Gather(&avg,1,MPI_FLOAT,D,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	
	if(rank==0){
		avg=0;
		for(i=0; i<N; i++){
            avg += D[i] / N;	
		}
		fprintf(stdout, "\nFinal Average = %f\n",avg);
	}

	MPI_Finalize();
	return 0;
}