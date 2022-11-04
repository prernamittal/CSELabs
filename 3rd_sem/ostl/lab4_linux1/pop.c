#include <stdio.h>
#define Size 4 
void Pop()
{
	int x, Top=-1, arr[Size];
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",arr[Top]);
		Top=Top-1;
	}
}
 