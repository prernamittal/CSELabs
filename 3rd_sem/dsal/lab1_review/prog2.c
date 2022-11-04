#include <stdio.h>
int Lsearch(int arr[],int n,int f)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (f==arr[i])
			return (i++);
	}
}
int main()
{
	int n,i,f,arr[5];
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for (i=0;i<n;i++)
	{
	scanf("%d", &arr[i]);
    }
    printf("Enter element to be found: ");
	scanf("%d",&f);
	if (Lsearch(arr,n,f)==0)
		printf("Not found");
	else
		printf("found at position: %d", Lsearch(arr,n,f));
	return 0;
}