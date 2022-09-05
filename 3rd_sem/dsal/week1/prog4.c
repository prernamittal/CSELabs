#include <stdio.h>
void seclarge(int arr[],int n )
{
	int i,largest, seclargest,x;
	if (n<2)
	{
		printf("invalid input");
		return;
	}
	largest=seclargest=x;
	for (i=0;i<n;i++)
	{
		if (arr[i]>largest)
		{
			seclargest=largest;
			largest = arr[i];
		}
		else if (arr[i] > seclargest)
            seclargest = arr[i];
	}
	if (seclargest == x)
        printf("no second largest element");
    else
        printf("second largest element is %d", seclargest);
}
int main()
{
    int i,n,arr[10];
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    seclarge(arr, n);
    return 0;
}