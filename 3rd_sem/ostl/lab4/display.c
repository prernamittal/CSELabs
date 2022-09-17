#include <stdio.h>
#define Size 4 
void display()
{
	int x, Top=-1, arr[Size];
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",arr[i]);
	}
}