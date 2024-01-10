#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, k=3,val=1;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	for(int i=0; i<rank; i++){
		val=val*k;
	}
	printf("%d\n", val);
	MPI_Finalize();
	return 0;
}
