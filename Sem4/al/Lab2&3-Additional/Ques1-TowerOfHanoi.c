//ques-recursive soln for tower of hanoi
#include <stdio.h>

void toh(int n, char from, char to, char temp){
    if (n==1){
        printf("\n Move disk from peg %c to peg %c", from, to);
        return;
    }
    toh(n-1,from,temp,to);
    printf("\n Move disk %d from peg %c to peg %c", n, from, to);
    toh(n-1,temp,to,from);
} 

int main(){
    int n;
    printf("Enter number of disks : ");
    scanf("%d", &n);
    printf("\nMoves are :\n");
    toh(n,'A','C','B');
}
