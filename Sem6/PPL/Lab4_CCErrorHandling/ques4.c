#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int rank,size,i,j,num,sum=0;
	int a[4][4],b[4][4];
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(rank==0){
		printf("Enter matrix elements: ")
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
	}
	
	int c[4],sumMat[4];	
	MPI_Scatter(a, 4, MPI_INT, c, 4, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scan(c, sumMat, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	MPI_Gather(sumMat, 4, MPI_INT, b, 4, MPI_INT, 0, MPI_COMM_WORLD);		
	
	if(rank==0){
		printf("Final result:\n");
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				printf("%d\t", b[i][j]);
			}
			printf("\n");
		}
	}
	
	MPI_Finalize();
}
