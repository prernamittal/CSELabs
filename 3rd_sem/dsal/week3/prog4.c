#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int day;
    int *month;
    int year;
} DOB;
typedef struct {
    int reg_no;
    char *name;
    char address[50];
} STU_INFO;
typedef struct {
    char *college_name;
    char uni_name[50];
} COLLEGE;
typedef struct {
    DOB *d;
    STU_INFO stu;
    COLLEGE col;
} STUDENT;
void read(STUDENT *s, int n)
{
for (int i=0;i<n;i++) 
    {
    printf("\nEnter details: ");
    printf("\nEnter day: ");
    scanf("%d",&((s+i)->d->day));
    printf("\nEnter month: ");
    scanf("%d",&((s+i)->d->month));
    printf("\nEnter year: ");
    scanf("%d",&((s+i)->d->year));

    printf("\nEnter reg_no.: ");
    scanf("%d",&((s+i)->stu.reg_no));
    printf("\nEnter name: ");
    scanf("%s[^\n]",&((s+i)->stu.name));
    printf("\nEnter address: ");
    scanf("%s[^\n]",&((s+i)->stu.address));

    printf("\nEnter college: ");
    scanf("%s[^\n]",&((s+i)->col.college_name));
    printf("\nEnter university: ");
    scanf("%s[^\n]",&((s+i)->col.uni_name));
    }    
}
void disp(STUDENT *s,int n) {
    for(int i=0;i<n;i++) {
        printf("\nDetails are:");
        printf("\nThe name is : %s", (s+i)->stu.name);
        printf("\nThe registration number is: %d", (s+i)->stu.reg_no);

    }
}
int main() {
    
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    STUDENT *s;
    s = (STUDENT *)malloc(n*sizeof(STUDENT *));
    read(s,n);
    return 0;
}
