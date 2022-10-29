#include<stdio.h>
#define MAX 5
int arr[MAX];
int front = -1;
int rear = -1;
void insertcq(int ele)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("overflow\n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
arr[rear] = ele ;
}
void deletecq()
{
if(front == -1)
{
printf("underflow\n");
return ;
}
printf("Element deleted: %dn",arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}
void displaycq()
{
int f = front,r = rear;
if(front == -1)
{
printf("empty\n");
return;
}
printf("Q elements :\n");
if( f <= r )
while(f <= r)
{
printf("%d ",arr[f]);
f++;
}
else
{
while(f <= MAX-1)
{
printf("%d ",arr[f]);
f++;
}
f = 0;
while(f <= r)
{
printf("%d ",arr[f]);
f++;
}
}
printf("n");
}
int main()
{
int choice,ele;
do
{
printf("1.Insert 2.Delete 3.Display 4.Quit \nEnter choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Enter element to insert: \n");
scanf("%d", &ele);
insertcq(ele);
break;
case 2 :
deletecq();
break;
case 3:
displaycq();
break;
case 4:
break;
default:
printf("Wrong choice");
}
}while(choice!=4);
return 0;
}