#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("\nRank = %d\n", rank);
	if(rank==0){
		int low=1, high=50, flag;
		while(low<high){
			flag=0;
			if(low<=1){
				++low;
				continue;
			}
			for(int i=2; i<=low/2; ++i){
				if(low%i ==0){
					flag=1;
					break;
				}
			}
			if(flag==0) printf("%d, ", low);
			++low;
		}
	}
	else{
		int low=51, high=100, flag;
		while(low<high){
			flag=0;
			if(low<=51){
				++low;
				continue;
			}
			for(int i=2; i<=low/2; ++i){
				if(low%i ==0){
					flag=1;
					break;
				}
			}
			if(flag==0) printf("%d, ", low);
			++low;
		}
		
	}
	MPI_Finalize();
	return 0;
}
