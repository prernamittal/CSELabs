#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 20
int top=-1, arr[size];
void push(char x)
{
    arr[++top]=x;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return arr[top--];
}
int precedence(char op)
{
    if(op==')')
    return 0;
    else if(op=='+'||op=='-')
    return 1;
    else if(op=='*'||op=='/')
    return 2;
}
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void itp(char infix[size], char prefix[size])
{
    char temp,x;
    int i=0,j=0;
    strrev(infix);
    while(infix[i]!='\0')
    {
        temp=infix[i];
        if(isalnum(temp))
        {
            prefix[j++]=temp;
        }
        else if (temp==')')
        push(temp);
        else if(temp=='(')
        {
            while(x=pop()!=')')
            {
                prefix[j++]=x;
            }
        }
        else
        {  while(precedence(arr[top])>=precedence(temp))
            {prefix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
}
int main()
{
    char infix[size], prefix[size];
    printf("Enter the infix expression: ");
    scanf("%s[^/]",infix);
    itp(infix, prefix);
    printf("Prefix expression is: %s\n", prefix);
}
