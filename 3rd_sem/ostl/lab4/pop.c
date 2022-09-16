#include <stdio.h>
int pop(int *arr, int tos)
{
	if(tos==-1)
		return -5;
	else 
	{
		arr[tos]=-2;
		tos-=1;
		return tos;
	}
}
