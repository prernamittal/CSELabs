#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
}*list1=NULL,*list2=NULL,*list=NULL;
void insert(char data)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    struct Node *curr;
    new->data=data;
    new->next=NULL;
}
void display(struct Node *head)
{
    int temp;
    struct Node *ptr=head;
    if(head==NULL)
    {
        printf("not initialized");
    }
    else if(head->next==head)
    {
    printf("%d",head->data);
    return;
    }
    while(ptr->next!=head)
    {
        printf("%d", ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
void merge()//incomplete function
{
    struct node *l1,*l2;
    l1=list;
}
int main()
{
    printf("Enter list1: ");
    printf("List1: ");
    display(list1);
    printf("Enter list2: ");
    printf("List2: ");
    display(list2);
    printf("Merged List: ");
    display(list);
}

