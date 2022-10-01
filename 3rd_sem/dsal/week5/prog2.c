#include <stdio.h>
#include <stdlib.h>
#define size 10
int stack[size], top=-1,i,n;
void push(int n)
{
    ++top;
    stack[top]=n;
}
int pop()
{
    return stack[top];
}
void main()
{
    int dec, total=0,ele;
    printf("enter decimal number: ");
    scanf("%d", &dec);
    while(dec>0)
    {
       total = dec % 2;
       push(total);
       dec /= 2;
    }
    for(i=top;top>-1;top--)
    {
        ele = pop();
        printf("%d\n", ele);
    }
}