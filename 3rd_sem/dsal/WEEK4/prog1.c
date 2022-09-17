#include <stdio.h>
int fibo(int n)
{
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return (fibo(n-1)+fibo(n-2));    
}
int main()
{
    int n,x=0,i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fibonacci series is: ");
    for(i=1;i<=n;i++)
    {
        printf("%d\n", fibo(x));
        x++;
    }
    return 0;    
}