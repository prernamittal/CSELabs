#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, op1=5, op2=10;
	char operator = '*';
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(operator=='+' && rank==0){
		printf("value: %d", (op1+op2));
		printf("\nprocess rank: %d", rank);
	}
	else if(operator=='-' && rank==1){
		printf("value: %d", (op1-op2));
		printf("\nprocess rank: %d", rank);
	}
	else if(operator=='*' && rank==2){
		printf("value: %d", (op1*op2));
		printf("\nprocess rank: %d", rank);
	}
	else if(rank==3){
		printf("value: %d", (op1/op2));
		printf("\nprocess rank: %d", rank);
	}
	MPI_Finalize();
	return 0;
}
