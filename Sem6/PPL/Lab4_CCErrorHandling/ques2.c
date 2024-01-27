#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char* argv[]){
	int rank,size,i, n;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	double mypi, pi, h, x,sum=0.0;
	double PI25DT=3.141592653589793238462643383279502884197169399375105820974944;
                                                                                  
	if(rank==0){
		printf("Enter n: ");
		scanf("%d", &n);
	}
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	h=1.0/(double)n;
	sum=0.0;
	for(i=rank+1; i<=n; i+=size){
		x=h*((double)i -0.5);
		sum+=4.0/(1.0+x*x);
	}

	mypi=h*sum;
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank==0){
		printf("pi is approx %.16f, error is %.16f\n", pi, fabs(pi-PI25DT));
	}
	MPI_Finalize();
}