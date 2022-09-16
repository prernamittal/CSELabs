#include <stdio.h>
int push(int *arr, int n, int tos, int x)
{
	if((tos+1)>(n-1))
	{
		return -1;
	}
	else
	{
		tos +=1;
		arr[tos]=x;
		return tos;
	}
}
