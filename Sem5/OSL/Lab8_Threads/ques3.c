#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *args){
	int *arr = (int *)args;
	int low = arr[0];
	int high = arr[1];
	int *sieve = (int *)calloc(high + 1, sizeof(int));
	for (int i = 0; i <= high; i++){
		sieve[i] = 1;
	}
	sieve[0] = 0;
	sieve[1] = 0;
	for (int i = 2; i * i <= high; i++){
		if (sieve[i] == 1){
			for (int j = i * i; j <= high; j += i){
				sieve[j] = 0;
			}
		}
	}
	return (void *)sieve;
}

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Insufficient arguments\n");
		exit(1);
	}
	int low = atoi(argv[1]);
	int high = atoi(argv[2]);
	int packet[] = {low, high}, *ans;
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void *)packet);
	pthread_join(thread, (void **)&ans);
	printf("Prime Numbers: ");
	for (int i = low; i < high; i++){
		if (ans[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}