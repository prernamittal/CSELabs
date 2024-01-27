#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int rank,size,fact=1, factsum, i, error;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

	//purposely produce error
	error=MPI_Bcast(&fact, 1, MPI_INT, 0, MPI_COMM_NULL);
	 
	if(rank==0){
		if (error != MPI_SUCCESS) {
		char s[100];
		int len, class;
		MPI_Error_string(error, s, &len);
		MPI_Error_class(error, &class);
		fprintf(stderr, "Error description is %s\n", s);
		fflush(stderr);
		fprintf(stderr, "Error class is %d\n", class);
		fflush(stderr);
		}
	}

	for(i=1; i<=rank+1; i++)
		fact = fact * i;
	MPI_Scan(&fact,&factsum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	if(rank==size-1)
		printf("Sum of all the factorial=%d\n",factsum);
	MPI_Finalize();
}