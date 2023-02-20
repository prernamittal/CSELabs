//matrix multiplication using brute-force technique
#include <stdio.h>
int main(){
    int a[20][20],b[20][20],c[20][250],i,j,k,r,s,m,n;
    printf("Enter dimensions of first matrix: \n");
    scanf("%d%d",&m,&n);
    printf("Enter dimensions of second matrix: \n");
    scanf("%d%d",&r,&s);
    if(m!=r)
    printf("\n The matrix cannot multiplied");
    else{
        printf("\n Enter the elements of first matrix: ");
        for(i= 0;i<m;i++){
            for(j=0;j<n;j++)
                scanf("\t%d",&a[i][j]);
        }
        printf("\n Enter the elements of second matrix: ");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                scanf("\t%d",&b[i][j]);
        }
        for(i=0;i<m;i++){
            printf("\n");
            for(j=0;j<n;j++){
                c[i][j]=0;
                for(k=0;k<m;k++)
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    printf("\n Multiplication is: ");
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("\t%d",c[i][j]);
    }
}