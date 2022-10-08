#include <stdio.h>
#include <string.h>
int stack[20], top=-1;
void push(int num)
{
    stack[top++]=num;
}
int pop()
{
    return(stack[top--]);
}
int op(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    else
    return 0;
}
int main()
{
    char prefix[20];
    int val,op1,op2,len,i,result;
    printf("Enter prefix expression: ");
    scanf("%s[^/]", prefix);
    len=strlen(prefix);
    for(i=len-1;i>=0;i--)
    {
        switch(op(prefix[i]))
        {
            case 0: 
            val=prefix[i];
            push(val-'0');
            break;

            case 1:
            op1=pop();
            op2=pop();

            switch(prefix[i])
            {
                case '+':
                result=op1+op2;
                break;

                case '-':
                result=op1-op2;
                break;

                case '*':
                result=op1*op2;
                break;

                case '/':
                result=op1/op2;
                break;
            }
            push(result);
            break;
        }
    }
    printf("Result is: %d\n", stack[top]);
}
