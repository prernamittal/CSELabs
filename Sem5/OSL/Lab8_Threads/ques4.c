#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *addOdd(void *args){
	int *arr = (int *)args;
	int n = arr[0];
	int *ans = (int *)malloc(sizeof(int));
	*ans = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] & 1)
			*ans += arr[i];
	}
	return (void *)ans;
}

void *addEven(void *args){
	int *arr = (int *)args;
	int n = arr[0];
	int *ans = (int *)malloc(sizeof(int));
	*ans = 0;
	for (int i = 1; i <= n; i++){
		if (!(arr[i] & 1))
			*ans += arr[i];
	}
	return (void *)ans;
}

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Insufficient arguments\n");
		exit(1);
	}
	int n = argc - 1;
	int *arr = (int *)calloc(n + 1, sizeof(int)), *even, *odd;
	arr[0] = n;
	for (int i = 0; i < n; i++){
		arr[i + 1] = atoi(argv[i + 1]);
	}
	pthread_t threadOdd, threadEven;
	pthread_create(&threadOdd, 0, &addOdd, (void *)arr);
	pthread_create(&threadEven, 0, &addEven, (void *)arr);
	pthread_join(threadOdd, (void **)&odd);
	pthread_join(threadEven, (void **)&even);
	printf("Sum of odd numbers: %d\n", *odd);
	printf("Sum of even numbers: %d\n", *even);
	return 0;
}