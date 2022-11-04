#include <stdio.h>
#include <stdlib.h>
int Smallest(int *arr, int n)
{
    int small= *arr;
    for (int i=0;i<n;i++)
    {
        if (small>arr[i])
        small=arr[i];
    }
    return small;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr=(int *)calloc(n,sizeof(int));
    printf("Enter elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int small = Smallest(arr,n);
    printf("Smallest element is: %d\n", small);

}