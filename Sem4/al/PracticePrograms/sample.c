#include <stdio.h>
int gcd(int n1,int n2){
    int gcd;
    int x=n1<n2?n1:n2;
    for(int i=x;i>=1;i--){
        if(n1%i==0 && n2%i==0){
            gcd=i;
            break;
        }
    }
    return gcd;
}
int maxfrequency(int A[], int n){
    int currcount=0, maxcount=0, maxele;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i]==A[j]){
                currcount++;
            }
        }
        if(currcount>maxcount){
            maxcount=currcount;
            maxele=A[i];
        }
    }
    printf("maxcount: %d", maxcount);
    return maxele;
}
int minfrequency(int A[], int n){
    int currcount=0, mincount=n, minele;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i]==A[j]){
                currcount++;
            }
        }
        if(currcount<mincount){
            mincount=currcount;
            minele=A[i];
        }
    }
    printf("\nmincount: %d", mincount);
    return minele;
}
int main(){
    int A[]={1,1,1,1,3,3,2,2,3};
    int n=9;
    // printf("Enter the array size: ");
    // scanf("%d", &n);
    // printf("Enter the array elements: ");
    // for(int i=0;i<n;i++){
    //     scanf("%d", &A[i]);
    // }
    int maxele=maxfrequency(A,n);
    printf("\nele with max frequency: %d", maxele);
    int minele=minfrequency(A,n);
    printf("\nele with min frequency: %d", minele);
}