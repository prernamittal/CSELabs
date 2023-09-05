#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *args) {
	int *arr = (int *)args;
	int n = arr[0];
	arr[1] = 0;
	arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Insufficient arguments\n");
		exit(1);
	}
	int n = atoi(argv[1]);
	int *arr = (int *)calloc(n + 1, sizeof(int));
	arr[0] = n;
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void *)arr);
	pthread_join(thread, 0);
	printf("Fibonacci Series: ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}