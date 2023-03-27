#include <stdio.h>
#include <stdlib.h>

int opcount=0;
void swap(int *arr , int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int split(int *arr, int l, int r){
    int first =l+1;
    int pivot=l;
    int last = r;
    while(1){
        while(arr[first]<=arr[pivot]){
            opcount++;
            first++;
        }
        opcount++;
        while(arr[last]>arr[pivot]){
            opcount++;
            last--;
        }
        opcount++;
        if(first>=last){
            break;
        }
        swap(arr,first,last);
    }
    swap(arr,pivot,last);
    return last;
}
void quicksort(int *arr, int l, int r){
	if (l<r){
		int sep = split(arr, l, r);
		printf("L: %d R: %d Split: %d\n", l, r, sep);
		quicksort(arr,l,sep-1);
		quicksort(arr,sep+1,r);
	}
}
int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter array elements: ");
	int *arr = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	quicksort(arr,0,n-1);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\nopcount: %d", opcount);
}
