#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct
{
    int day, month, year;
} DATE;
typedef struct 
{
    int house , zip;
    char state[50];
} ADDRESS;
typedef struct 
{
    char name[50];
    DATE d;
    ADDRESS a;
} EMPLOYEE;
void read(EMPLOYEE *e, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter name: ");
        scanf("%s[^\n]", &((e+i)->name));
        printf("Enter day: ");
        scanf("%d", &((e+i)->d.day));
        printf("Enter month: ");
        scanf("%d", &((e+i)->d.month));
        printf("Enter year: ");
        scanf("%d", &((e+i)->d.year));
        printf("Enter house no.: ");
        scanf("%d", &((e+i)->a.house));
        printf("Enter zip: ");
        scanf("%d", &((e+i)->a.zip));
        printf("Enter state: ");
        scanf("%s[^\n]", &((e+i)->a.state));
    }
}
void disp(EMPLOYEE *e, int n)
    {
        for(int i=0;i<n;i++)
        {
            printf("Details are: \nname is: %s", (e+i)->name);
            printf("\nDOB is : %d/%d/%d", (e+i)->d.day, (e+i)->d.month, (e+i)->d.year);
            printf("\nHouse number: %d", (e+i)->a.house);
            printf("\nzip code: %d", (e+i)->a.zip);
            printf("\nState: %s", (e+i)->a.state);
        }
    }
int main() { 
    int n;
    printf("Enter number of employees ");
    scanf("%d",&n);
    EMPLOYEE * e;
    e = (EMPLOYEE *) malloc(n*sizeof(EMPLOYEE *));
    read(e,n);
    disp(e,n);
    return 0;
}