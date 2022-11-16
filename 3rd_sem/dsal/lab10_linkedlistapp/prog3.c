#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void create(int n)
{
    int i, data;
    struct node *new;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &data);
            new->data = data;
            new->prev = last; 
            new->next = NULL;
            last->next = new; 
            last = new; 
        }
        printf("\nlinked list created\n");
    }
}
void display()
{
    struct node *temp;
    int n = 1;
    if(head == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        temp = head;
        printf("elements are: \n");
        while(temp != NULL)
        {
            printf("%d", temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void reverse()
{
    struct node *curr, *temp;
    curr = head;
    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }
    temp = head;
    head = last;
    last = temp;
    printf("List reversed\n");
}
int main()
{
    int n, data, choice;
    head = last= NULL;
    do
    {
        printf("\n1. Create\n2. Reverse\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter total nodes: ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
        }
    }while(choice!=4);
    return 0;
}