#include <stdio.h>
#define Size 4 
void Push()
{
	int x, Top=-1, arr[Size];
	if(Top==Size-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted:");
		scanf("%d",&x);
		Top=Top+1;
		arr[Top]=x;
	}
}
 