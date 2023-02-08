#include<stdio.h>
#include <stdlib.h>

int gcdmin(int a, int b){
	int opcount = 0, t=0;
    t = (a<b?a:b);
	do{
			opcount++;
			if(a%t==0 && b%t==0)
				break;
			else
				t--;
	} while(b/t!=0);
	printf("opcount = %d\n",opcount);
	return t;
}

int main(){
	printf("Enter values of a and b :\n");
	int a,b;
	scanf("%d%d",&a, &b);
	int result = gcdmin(a,b);
	if(result==0)
		printf("gcd of %d & %d is undefined\n",a,b);	
	else
		printf("gcd of %d & %d = %d\n",a,b,result);
}