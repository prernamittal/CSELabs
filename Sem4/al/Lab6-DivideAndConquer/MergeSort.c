#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int first, int mid, int last){
    int i=0,j=0,opcount=0,k=first;
    int na=mid-first+1;
    int nb=last-mid;
    int a[na],b[nb];
    for(int i=0;i<na;i++){
        a[i]=arr[i+first];
    }
    for(int i=0;i<nb;i++){
        b[i]=arr[i+mid+1];
    }
    while(i<na && j<nb){
        opcount++;
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<na){
        opcount++;
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<nb){
        opcount++;
        arr[k]=b[j];
        j++;
        k++;
    }
}
void mergesort(int *arr, int first, int last){
    if(first<last){
    int mid=first+(last-first)/2;
    mergesort(arr,first,mid);
    mergesort(arr,mid+1,last);
    merge(arr,first,mid,last);
    }
}
int main(){
    int n, opcount=0;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr=(int*)calloc(n, sizeof(int));
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\nopcount: %d", opcount);
}