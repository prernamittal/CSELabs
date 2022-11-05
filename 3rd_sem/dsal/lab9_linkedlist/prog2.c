#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*list1=NULL,*list2=NULL,*cup,*cap;
void insert(struct Node **head, int num)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=num;
    new->next=*head;
    *head=new;
}
void display(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
        if(ptr!=NULL)
        printf("\t");
    }    
}
int search(struct Node *head, int num)
{
    while(head!=NULL)
    {
        if(head->data==num)
        {
            return 1;
        }
        head=head->next;
    }
    return 0;
}
struct Node *cupll(struct Node *list1, struct Node *list2)
{
    cup=NULL;
    struct Node *temp=list1;
    while(temp!=NULL)
    {
        insert(&cup, temp->data);
        temp=temp->next;
    }
    while(list2!=NULL)
    {
        if(!search(list1,list2->data))
        {
            insert(&cup,list2->data);
        }
        list2=list2->next;
    }
    return cup; 
}
struct Node *capll(struct Node *list1, struct Node *list2)
{
    cap=NULL;
    while(list1!=NULL)
    {
        if(search(list2,list1->data))
        {
            insert(&cap,list1->data);
        }
        list1=list1->next;
    }
    return cap;
}
int main()
{
    int nl1,nl2,temp;
    printf("Enter no. of nodes in list1: ");
    scanf("%d",&nl1);
    printf("Enter data: ");
    for(int i=0;i<nl1;i++)
    {
        scanf("%d",&temp);
        insert(&list1,temp);
    }
    printf("List 1 is: ");
    display(list1);
    printf("\nEnter no. of nodes in list2: ");
    scanf("%d",&nl2);
    printf("Enter data: ");
    for(int i=0;i<nl2;i++)
    {
        scanf("%d",&temp);
        insert(&list2,temp);
    }
    printf("List 2 is: ");
    display(list2);
    cupll(list1,list2);
    capll(list1,list2);
    printf("\nUnion List: ");
    display(cup);
    printf("\nIntersection List: ");
    display(cap);
}
