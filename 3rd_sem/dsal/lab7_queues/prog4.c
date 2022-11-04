#include <stdio.h>
#include<stdlib.h>
#define size 20

int s1[size], s2[size]; 
int t1 = -1; 
int t2 = -1; 
int count = 0; 
void push1 (int ele)
{
     if (t1 == size - 1){
        printf ("S1 overflow");
        return;
      }

     else{
        t1++;
        s1[t1] = ele;
     }

    return;
}
void push2 (int ele)
{
      if (t2 == size - 1){
         printf ("S2 overflow");
         return;
       }
       else
       {
           t2++;
           s2[t2] = ele;
       }
       return;
}

int pop1()
{
      if (t1 == -1){
          printf ("S1 underflow\n");
          return -1;
      }

       return s1[t1--];
}
int pop2()
{
     if (t2 == -1)
     {
         printf ("S2 underflow\n");
         return -1;
    }
     return s2[t2--];
}
void enqueue(int ele)
{
     push1(ele);
     count++;
}
void dequeue()
{
      if (t1 == -1 && t2 == -1)
         printf ("Queue is empty\n");
     else {
         for (int i = 0; i < count; i++){
            int temp = pop1();
            push2 (temp);
      }
      int x = pop2();
      printf ("Dequeued element is %d\n", x);
      count--;
      for (int i = 0; i < count; i++){
              int temp = pop2();
             push1 (temp);
       }
   }
}
void display()
{
if (t1==-1)
{
printf ("Queue is empty \n");
return;
}
for (int i = 0; i < t1; i++)
printf ("%d ", s1[i]);
printf ("\n");
}
void top()
{
      printf ("Top element is %d ", s1[0]);
}
int main ()
{
    enqueue (2);
    enqueue (42);
    enqueue (-1);
    display();
    dequeue ();
    enqueue (-1);
    display ();
    return 0;
}