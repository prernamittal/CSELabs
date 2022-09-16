#include<stdio.h>
#include<stdlib.h>
#include "maths.h"
int main()
{
	int i,n,*arr, input, tos=-1,x;
	printf("\nEnter size: ");
	scanf("%d", &n);
	arr=(int *)calloc(n,sizeof(int));
	do
	{
		printf("\nEnter 1 to push, 2 to pop, 3 to display: \n");
		scanf("%d", &input);
		if(input==1)
		{
			printf("\nEnter no to be pushed: ");
			scanf("%d", &x);
			tos = push(arr, n, tos,x);
			if(tos==-1)
				printf("\noverflow");
		}
		else if(input==2)
		{
			tos= pop(arr,tos);
			printf("\nno element to pop\n");
		}
		else if(input==3)
		{
			printf("\n");
			display(arr,tos);
		}
		else 
		{
			input=-1;
			printf("\nexit\n");
		}
	}
	while (input != -1);
	return 0;
}
