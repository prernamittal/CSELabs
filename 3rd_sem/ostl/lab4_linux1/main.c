#include<stdio.h>
#include<stdlib.h>
#define Size 4 
int Top=-1, arr[Size];
void Push();
void Pop();
void display();
int main()
{
	int choice;
	while(1)	
	{
		printf("\nEnter 1.Push the element\n2.Pop the element\n3.Show\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Push();
					break;
			case 2: Pop();
					break;
			case 3: display();
					break;
			default: exit(0);
		}
	}
}
