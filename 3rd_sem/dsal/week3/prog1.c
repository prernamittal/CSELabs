#include <stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
    int r;
    int img;
} COMPLEX;
void read(COMPLEX *c1)
{
    printf("Enter numbers: ");
    scanf("%d%d", &c1->r, &c1->img);
}
void add(COMPLEX *c1, COMPLEX *c2, COMPLEX *ans)
{
    ans->r=c1->r+c2->r;
    ans->img=c1->img+c2->img;
}
void sub(COMPLEX *c1, COMPLEX *c2, COMPLEX *ans)
{
    ans->r=c1->r-c2->r;
    ans->img=c1->img-c2->img;
}
void mult(COMPLEX *c1, COMPLEX *c2, COMPLEX *ans)
{
    ans->r=c1->r*c2->r-c1->img*c2->img;
    ans->img=c1->r*c2->img+c1->img*c2->r;
}
void disp(COMPLEX *c)
{
    if(c->img>0)
    {
        printf("%d + %di", c->r, c->img);
    }
    else if(c->img<0)
    {
        printf("%d - %di", c->r, abs(c->img));
    }
    else
        printf("%d + %di", c->r, c->img); 
}
int main()
{
    COMPLEX x,y,sum,diff,prod;
    read(&x);
    read(&y);
    add(&x, &y, &sum);
    sub(&x, &y, &diff);
    mult(&x, &y, &prod);
    printf("sum is: ");
    disp(&sum);
    printf("\ndifference is: ");
    disp(&diff);
    printf("\nproduct is: ");
    disp(&prod);
    return 0;
}