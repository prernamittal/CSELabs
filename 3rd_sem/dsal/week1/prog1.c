#include <stdio.h>
double add(double arr[],int n)
{
	int i;
	double s=0;
	for (i=0;i<n;i++)
	{
		s+=arr[i];
	}
	return s;
}
int main(){
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	double arr[n];
	printf("Enter elements: ");
	for (i=0;i<n;i++){
		scanf("%lf", &arr[i]);
	}
	printf("The sum of array is %lf", add(arr,n));
	return 0;
}