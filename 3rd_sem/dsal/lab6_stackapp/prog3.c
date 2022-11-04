#include <stdio.h>  
#define size 20  
int arr[size];
int top1=-1, top2=size;  
void push1(int x)  
{  
    if(top1<top2-1)  
    {  
    arr[++top1]=x;  
    }  
    else  
    {  
    printf ("overflow\n");  
    }  
}  
void push2(int x)  
{  
if(top1<top2-1)  
    {  
    arr[--top2]=x;   
    }  
    else  
    {  
    printf ("overflow\n");  
    }  
}  
void pop1()  
{  
    if (top1>=0)  
    {  
    int ele=arr[top1--];  
    printf ("%d is popped\n", ele);  
    }  
    else  
    {  
    printf ("underflow\n");  
    }  
}  
void pop2 ()  
{  
if (top2<size)  
    {  
    int ele=arr[top2--];  
    printf ("%d is popped\n", ele);  
    }  
    else  
    {  
    printf ("underflow\n");  
    }  
}  
void display1()  
{  
    for(int i=0;i<=top1;i++)  
    {  
    printf("%d ",arr[i]);  
    }  
    printf("\n");  
}  
void display2()  
{  
    for(int i=top2;i<size;++i)  
    {  
    printf("%d ",arr[i]);  
    }  
    printf("\n");  
}  
int main()  
{  
    int arr[size],num;  
    for (int i=1;i<=10;++i)  
        {  
        push1(i);  
        printf ("%d pushed in stack1\n", i);  
        }  
    for (int i=11;i<=20;++i)  
        {  
        push2(i);  
        printf ("%d pushed in  stack2\n", i);  
        }  
    display1();  
    display2();  
    num=top1++;  
    while(num)  
    {  
    pop1();
    --num;  
    } 
    int n=top2++; 
    while(n==size)  
    {  
    pop2();
    --n;  
    }  
    return 0;  
}  