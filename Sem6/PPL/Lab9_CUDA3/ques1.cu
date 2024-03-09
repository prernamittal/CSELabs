#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void addMatrix (double *matA,double *matB,double *matC,int length){
	int i=blockIdx.x * blockDim.x + threadIdx.x;
	int j=blockIdx.y * blockDim.y + threadIdx.y;
	int k = i+j*length;
	if(i<length&&j<length)
		matC[k] = matA[k]+matB[k];	
}

int main(void){
	
	return 0;
}