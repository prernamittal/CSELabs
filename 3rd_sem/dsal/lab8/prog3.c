//incomplete
#include <stdio.h>
#include<stdlib.h>
#define size 20

int s[size]; 
int top = -1; 
int count = 0; 
void push(char c)
{
     if (top == size - 1){
        printf ("overflow");
        return;
      }
     else{
        top++;
        s[top] = c;
     }
    return;
}
int pop()
{
      if (top == -1){
          printf ("underflow\n");
          return -1;
      }
       return s[top--];
}
void enqueue(char c)
{
     push(c);
     count++;
}
void dequeue()
{
      if (top == -1)
         printf ("Queue is empty\n");
     else {
         for (int i = 0; i < count; i++){
            char temp = pop();
            push(temp);
      }
      char ch = pop();
      printf("Dequeued element is %s\n", ch);
      count--;
      for (int i = 0; i < count; i++){
              char temp = pop();
             push(temp);
       }
   }
}
void display()
{
if (top==-1)
{
printf ("Queue is empty \n");
return;
}
for(int i=0;i<top;i++)
printf ("%s ", s[i]);
printf ("\n");
}
int compare(char p1, char p2)
{
    if(p1==p2)
    {
        return 1;
    }
    else
    return 0;
}
int main()
{
    char c[size];
    printf("Enter string: ");
    scanf("%s[^\n]", c);
}