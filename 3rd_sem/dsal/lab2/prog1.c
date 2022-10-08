#include <stdio.h>
#include <stdlib.h>
void Reverse(int *arr, int n);
int main ()
{
    int n,i;
    printf("Enter number of elements");
    scanf("%d", &n);
    int arr[10];
    printf("Enter elements of array");
    for (i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int *last;
    last =arr+n-1;
    int *p;
    for (p=arr;p<=last;p++,last--)
    {
        int temp=*p;
        *p=*last;
        *last=temp;
    }
    printf("Reversed array is: ");
    Reverse(arr,n);
}
void Reverse(int *arr, int n)
{
    int *arrend = arr+n-1;
    while(arr<=arrend)
    {
        printf("%d", *arr);
        arr++;
    }
}