#include <stdio.h>
void main(){
    int n1, n2, i,x, gcd, opcount=0;
    printf("Enter n1 and n2: ");
    scanf("%d %d",&n1, &n2);
    x=n1<n2?n1:n2;
    for(i=x;i>=1;i--){
        opcount++;
        printf("opcount: %d", opcount);
        if(n1%i==0 && n2&i==0){
            gcd=i;
            break;
        }
    }
    printf("The gcd is %d\nopcount=%d", gcd,opcount);
}