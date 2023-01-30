#include<stdio.h>
#define size 5

void init(int arr[][size]){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            arr[i][j] = 0;
}

void addedge(int arr[][size],int src, int dest){
     arr[src][dest] = 1;
}

void displaymatrix(int arr[][size]){
     for(int i = 0; i < size; i++){
         for(int j = 0; j < size; j++){
             printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
}

int main(){
    int adjMatrix[size][size];
    init(adjMatrix);
    addedge(adjMatrix,0,0);
    addedge(adjMatrix,0,1);
    addedge(adjMatrix,1,3);
    addedge(adjMatrix,2,3);
    addedge(adjMatrix,1,4);
    addedge(adjMatrix,3,3);
    addedge(adjMatrix,3,1);
    displaymatrix(adjMatrix);
}
