#include <stdio.h>
#include <math.h>

void main(){
    int n, A[100], open=0, close=0;
    printf("Enter the number of lockers: ");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        A[i]=0;//all lockers are closed(0) initially
    }
    int s=sqrt(n);
    for(int i=0;i<s;i++){
        A[i*i]=1; //open(1) lockers at the end are perfect squares
    }
    for(int i=0;i<n;i++){
        if (A[i]==1){
            open+=1;
        }
        else
        {
            close+=1;
        }
    }
    printf("%d lockers are open and %d lockers are closed", open, close);
}