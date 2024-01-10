#include <mpi.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	int rank;
	char input[5] = "Hello";
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank<5){
		if(isupper(input[rank]))
		input[rank] = tolower(input[rank]);
	else 
		input[rank] = toupper(input[rank]);
	printf("%s\n", input);
	}
	MPI_Finalize();
	return 0;
}
