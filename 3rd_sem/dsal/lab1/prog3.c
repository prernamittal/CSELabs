#include <stdio.h>
void matprod(int a[][10], int b[][10], int r,int c,int m,int n)
{
	int max[10][10],i,j,k;
	if (r!=c)
		printf("Invalid input");
	else
	{
		for (i=0;i<r;i++)
		{
			for (j=0;j<n;j++)
			{
				max[i][j]=0;
				for (k=0;k<c;k++)
				{
					max[i][j]+=(a[i][k]*b[k][j]);
				}
			}
		}
	}
	printf("elements of product matrix are: ");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d\t", max[i][j]);
		}
		printf("\n");
	}

}
int main()
{
	int a[10][10],b[10][10], r,c,m,n,i,j;
	printf("Enter size of first array: ");
	scanf("%d%d", &r,&c);
	printf("Enter elements of 1st array: ");
	for (i=0;i<r;i++){
		for (j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter size of second array");
	scanf("%d%d", &m,&n);
	printf("Enter elements of 2nd array: ");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	matprod(a,b,r,c,m,n);
	return 0;

}