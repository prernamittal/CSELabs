#include <stdio.h>
#include <stdlib.h>
#define size 10
typedef struct stacks{
    char arr[size];
    int top;
 }stack;
 void push(stack *s)
 {
    s->top=-1;
    if(s->top==size-1)
    {
        printf("\noverflow");
    }
    else
    {
        char n;
        printf("\nEnter element to push:");
        scanf(" %c", &n);
        s->arr[s->top++]=n;
    }
 }
 void pop(stack *s)
 {
    s->top=-1;
    if(s->top==-1)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\nDeleted element is: %c\n", s->arr[s->top--]);
    }
 }
 void display(stack *s)
 {
    if(s->top=-1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("\nfinal stack is: ");
        for(int i=s->top; i>=0;i--)
        {
            printf("%c\n",s->arr[i]);
        }
    }
 }
 
 int main()
 {
    stack s;
    while(1)
    {
        int choice;
        printf("\nEnter choice: 1. push\n2.pop\n3.display\nexit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push(&s);
            break;

            case 2:
            pop(&s);
            break;

            case 3:
            display(&s);        
            break;

            default:
            exit(0);
        }
    }
 }