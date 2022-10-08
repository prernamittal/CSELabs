#include <stdio.h>
double getavg(int *arr,int n);
void exchange(int *px,int *py);

double getavg(int *arr,int n)
    {
        int i,sum=0;
        double avg;
        for(i=0;i<n;i++)
        {
            sum += arr[i];
        }
        avg = (double) sum/n;
        return avg;
    }

void exchange(int *px, int *py)
{
    int temp=*px;
    *px= *py;
    *py=temp;
}

int main()
{
    char x;
    while (1)
    {
        printf("Enter q no.");
        scanf("%c",&x);
        if (x=='a'){
            int arr[5]={100,2,5,9,7};
            double avg;
            avg=getavg(arr,5);
            printf("Answer is %lf\n", avg);
            }
        if (x=='b')
        {
            int a,b;
            int *px=&a,*py=&b;
            printf("Enter 2 numbers: ");
            scanf("%d%d", px,py);
            exchange(px,py);
            printf("%d%d\n", a,b);
        }
        if (x=='c')
        {
            int a,*p,**q;
            a=58, p=&a; q=&p;
            printf("%d\n", a);
            printf("%d\n", *p);
            printf("%d\n", **q);
        }


    }

}