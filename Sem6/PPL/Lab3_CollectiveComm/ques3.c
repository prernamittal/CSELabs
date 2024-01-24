#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank,size,n, i;
	char A[10],B[10];

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int D[size];
	if(rank==0){
		fprintf(stdout,"Enter string divisible by %d:\n",size);
		scanf("%s", A);
		fflush(stdin);
		n=strlen(A)/size;
	}

	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(A,n,MPI_CHAR,B,n,MPI_CHAR,0,MPI_COMM_WORLD);
	fprintf(stdout,"\nI have received %c in process %d\n",A[i],rank);
	fflush(stdout);

	// non-vowel code
	int count=0;
    for (i = 0; i < n; i++) {
	    char ch = tolower(B[i]);
	    if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
	        count++;
    }

    MPI_Gather(&count,1,MPI_INT,D,1,MPI_INT,0,MPI_COMM_WORLD);

	if(rank==0){
		count=0;
		for(i=0; i<size; i++){
			count += D[i];
		}
		printf("\nFinal count of Non-Vowels: %d", count);
	}

	MPI_Finalize();
	return 0;
}