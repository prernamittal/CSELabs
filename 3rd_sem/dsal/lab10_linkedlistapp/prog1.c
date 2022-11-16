#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int data;
    struct node *prev;  
    struct node *next;  
};  
struct node *head;  
void insertbeg()  
{  
    struct node *ptr;   
    int val;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\noverflow");  
    }  
    else  
    {  
    printf("\nEnter data: ");  
    scanf("%d",&val);  
    if(head==NULL)  
    {  
        ptr->next = NULL;  
        ptr->prev=NULL;  
        ptr->data=val;  
        head=ptr;  
    }  
    else   
    {  
        ptr->data=val;  
        ptr->prev=NULL;  
        ptr->next = head;  
        head->prev=ptr;  
        head=ptr;  
    }  
    printf("\ninsertion successful\n");  
}      
}  
void insertend()  
{  
    struct node *ptr,*temp;  
    int val;  
    ptr = (struct node *) malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\noverflow");  
    }  
    else  
    {  
        printf("\nEnter data: ");  
        scanf("%d",&val);  
        ptr->data=val;  
        if(head == NULL)  
        {  
            ptr->next = NULL;  
            ptr->prev = NULL;  
            head = ptr;  
        }  
        else  
        {  
            temp = head;  
            while(temp->next!=NULL)  
            {  
                temp = temp->next;  
            }  
            temp->next = ptr;  
            ptr ->prev=temp;  
            ptr->next = NULL;  
            }  
                
        }  
        printf("\ninsertion successful\n");  
    }  
void delbeg()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nunderflow");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\ndeletion successful\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\ndeletion successful\n");  
    }  
}  
void delend()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nunderflow");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\ndeletion successful\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\ndeletion successful\n");  
    }  
}  
void display()  
{  
    struct node *ptr;  
    printf("\nData is: \n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
    void main ()  
    {  
    int choice =0;  
        do{  
            printf("\n1.insertbeg\n2.insertend\n3.delbeg\n4.delend\n5.Display\n6.Exit\nEnter choice:\n");  
            scanf("%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                insertbeg();  
                break;  
                case 2:  
                insertend();  
                break;  
                case 3: 
                delbeg(); 
                break;  
                case 4:  
                delend();
                break;  
                case 5:  
                display();  
                break;  
            }  
        }while(choice!=6);
    }  
