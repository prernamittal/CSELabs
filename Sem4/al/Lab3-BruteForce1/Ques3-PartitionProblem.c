#include <stdbool.h>
#include <stdio.h>

bool isSubsetSum(int arr[], int n, int sum){
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum);
	return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

bool partition(int arr[], int s){
	int sum = 0;
	for (int i = 0; i < s; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	return isSubsetSum(arr, s, sum / 2);
}

int main(){
	int n, arr[10];
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
	if (partition(arr, n) == true)
		printf("\nCan be divided into two subsets of equal sum\n");
	else
		printf("\nCan not be divided into two subsets of equal sum\n");
	return 0;
}
