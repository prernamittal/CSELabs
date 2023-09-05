#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3
#define n 3

struct v{
    unsigned int i;
    unsigned int j;
};

double A[N][N] = {{1.0, 2.0, 4.0}, {3.0, 4.0, 5.0}, {4.0, 5.0, 7.0}};
double B[N][N] = {{2.0, 3.0, 9.0}, {4.0, 5.0, 7.0}, {2.0, 3.0, 9.0}};
double C[N][N];

void * thread_code(void *arg){
    struct v *data = (struct v *)arg;
    unsigned int l;
    for(l=0; l < N; l++){
        unsigned int i=(data[l]).i;
        unsigned int j=(data[l]).j;
        double sum=0;
        unsigned int d;
        for (d = 0; d < N; d++){
            sum = sum + A[i][d]*B[d][j];
        }
        C[i][j] = sum;
        sum = 0;
    }
    return 0;
}

int main(void){
    pthread_t threads[n];
    unsigned int i, k;
    struct v **data;
    data = (struct v **)malloc(n * sizeof(struct v*));
    for(i = 0; i < n; i++){
        data[i] = (struct v *)malloc(n * sizeof(struct v));
        for(k = 0; k < n; k++){
            data[i][k].i = i;
            data[i][k].j = k;
        }
        pthread_create(&threads[i], NULL, thread_code, data[i]);
    }
    for(i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < N; i++){
        for (k = 0; k < N; k++){
            printf("%lf\t", C[i][k]);
        }
        printf("\n");
    }
    return 0;
}