#include <mpi/mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;

	int x;
	if(rank == 0){
		printf("Enter a number : ");
		scanf("%d", &x);
		MPI_Send(&x, 1, MPI_INT, rank+1, rank+1, MPI_COMM_WORLD);
		MPI_Recv(&x, 1, MPI_INT, size-1, rank, MPI_COMM_WORLD, &status);
		printf("value %d from process %d\n", x, rank);
	}
	else{
		MPI_Recv(&x, 1, MPI_INT, rank-1, rank, MPI_COMM_WORLD, &status);
		printf("value %d from process %d\n", x, rank);
		x++;
		MPI_Send(&x, 1, MPI_INT, (rank+1)%size, (rank+1)%size, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}