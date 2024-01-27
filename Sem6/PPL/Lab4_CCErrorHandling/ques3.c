#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int rank,size,i, ele, count=0, c;
	int a[3][3], b[3];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	 
	if(rank==0){
		printf("Enter elements: ");
		for(i=0; i<3; i++){
			for(int j=0; j<3; j++){
				scanf("%d", &a[i][j]);
			}
		}
		printf("Enter element to search: ");
		scanf("%d", &ele);
	}

	MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(a, 3, MPI_INT, b, 3, MPI_INT, 0, MPI_COMM_WORLD);
	 
	for (i = 0; i < 3; i++) {
		printf("%d ",b[i]);
		if (b[i] == ele) 
			count ++;
	}

	printf("\nProcess %d: %d occurrences\n",rank,count);
	MPI_Reduce(&count, &c, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	 
	if(rank == 0)
		printf("\nTotal no. of occurrences: %d\n",c);
 
	MPI_Finalize();
}
