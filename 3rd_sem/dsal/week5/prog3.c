#include <stdio.h>
#include <string.h>
#define size 10
int top=-1, front=0, stack[size];
void pop()
{
    top--;
}
void push(char c)
{
    top++;
    stack[top]=c;
}
void main()
{
    int i,choice;
    char arr[size],n;
    while(1){
    printf("Enter a string: ");
    scanf("%s[^/]", &arr);
            for (i = 0;arr[i]!='\0';i++)
            {
                n = arr[i];
                push(n);
            }
            for (i = 0;i < (strlen(arr)/2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("not a palindrome\n");
                    break; 
                }
            }
            if ((strlen(arr)/2)==front)
                printf("palindrome\n");
            front  =  0;
            top  =  -1;
            break;
    }
}