#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    char name[50];
    int roll;
    double cgpa;
} STUDENT;
void read(STUDENT *s, int n)
{
    for (int i=0;i<n;i++)
    {
        printf("\nEnter name: ");
        scanf("%s[^\n]",(s+i)->name);
        printf("\nEnter roll no: ");
        scanf("%d", &(s+i)->roll);
        printf("\nEnter cgpa: ");
        scanf("%lf", &(s+i)->cgpa);
    }
}
void disp(STUDENT *s, int n)
{
    for (int i=0;i<n;i++)
    {
        printf("\nname is: %s", ((s+i)->name));
        printf("\nroll number is: %d", ((s+i)->roll));
        printf("\ncgpa is: %lf", ((s+i)->cgpa));
    }
}
void sort(STUDENT *s, int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if((s+i)->roll, (s+j)->name)
            {
                STUDENT t=*(s+i);
                *(s+i)=*(s+j);
                *(s+j)=t;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n );
    STUDENT *s= malloc(sizeof(STUDENT));
    read(s,n);
    sort(s,n);
    disp(s,n);
}