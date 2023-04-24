#include <stdio.h>
#define INF 999
void printMatrix(int n,int matrix[][n]) ;

void floyd(int n, int graph[][n]) {
int matrix[n][n], i, j, k;
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
    matrix[i][j] = graph[i][j];

for (k = 0; k < n; k++) {
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
    if (matrix[i][k] + matrix[k][j] < matrix[i][j])
        matrix[i][j] = matrix[i][k] + matrix[k][j];
    }
}
}
printMatrix(n,matrix);
}

void printMatrix(int n, int matrix[][n]) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
    if (matrix[i][j] == INF)
    printf("%s", "INF");
    else
    printf("%4d", matrix[i][j]);
}
printf("\n");
}
}

int main() {
    int n;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter weights of edges. 999 for infinity\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
        printf("Enter weight of vertex %d %d: ",i,j);
        scanf("%d", &graph[i][j]);
        }
    }
    floyd(n, graph);
}