#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *args){
	int *arr = (int *)args;
	int n = arr[0];
	int *ans = (int *)malloc(sizeof(int));
	*ans = 0;
	for (int i = 1; i <= n; i++){
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
	int *arr = (int *)calloc(n + 1, sizeof(int)), *ans;
	arr[0] = n;
	for (int i = 0; i < n; i++){
		arr[i + 1] = atoi(argv[i + 1]);
	}
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void *)arr);
	pthread_join(thread, (void **)&ans);
	printf("Sum: %d\n", *ans);
	return 0;
}