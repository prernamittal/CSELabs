#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;
void insert(int val)
{
    struct Node *new;
    new=(struct Node*)malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if(front==NULL)
    front=rear=new;
    else
    {
        rear->next=new;
        rear=new;
    }
    printf("Inserted\n");
}
void delete()
{
    if(front==NULL)
    printf("Underflow\n");
    else
    {
        struct Node *temp=front;
        front=front->next;
        printf("%d deleted", temp->data);
        free(temp);
    }
}
void display()
{
    if(front==NULL)
    printf("Underflow");
    else
    {
        struct Node *temp=front;
        printf("Queue is: ");
        while(temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\t",temp->data);
    }
}
void main()
{
    int choice, val;
    do
    {
        printf("\nEnter choice: \n1.Insert\t2.Delete\n3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter value: ");
            scanf("%d",&val);
            insert(val);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
        }
    } while (choice!=4);
}