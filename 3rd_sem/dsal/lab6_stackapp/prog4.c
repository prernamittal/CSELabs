#include <stdio.h>
#include <string.h>
#define size 20
char arr[size], stack[size];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
int main()
{
    char c[20], op1,op2,op;
    printf("Enter prefix expression: ");
    scanf("%s[^/]", arr);
    int n=strlen(arr),j=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/')
        {
            push(arr[i]);
        }
        else
        {
            c[j++]=arr[i];
            while((top!=-1)&&(stack[top]=='q'))
            {
                op2=pop();
                op1=pop();
                c[j++]=pop();
            }
            push('q');
        }
    }
    c[j]='\0';
    printf("%s",c);
    return 0;
}
