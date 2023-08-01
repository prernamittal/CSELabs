#include<stdio.h>
#include<stdlib.h>

int opcount=0;

void heapify(int arr[], int curr){
    int root = (curr)/2;
    opcount++;
    while(root>0){
	    opcount++;
        if(arr[root]<arr[curr]){
            int temp = arr[root];
            arr[root] = arr[curr];
            arr[curr] = temp;
            curr = root;
            root = (curr)/2;
        }
        else
            return;
    }
}

int main(){
    int n;
    printf("\nEnter n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=1;i<=n;i++){
        printf("Enter element %d: ", i);
        scanf("%d",&arr[i]);
        heapify(arr,i);
    }
    printf("\nHeap: ");
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nOpcount: %d",opcount);
    return 0;
}