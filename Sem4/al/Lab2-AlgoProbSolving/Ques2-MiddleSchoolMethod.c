#include<stdio.h>
#include<stdlib.h>

int checkprime(int b,int* opcount){
	for(int i=2;i<b;i++){
		(*opcount)++;
		if(b==2)
			return 1;
		else{
			if(b%i == 0)
				return 0;
		}
	}
	return 1;
}

int msmethod(int a,int b,int* opcount){
	int gcd = 1,i=2;
	int t = (a<b?a:b);
	do {
		(*opcount)++;
		if(a == 1 && b == 1)
			break;
		if(checkprime(i,opcount)){
			if(a%i == 0 && b%i == 0){
				gcd *= i;
				a /=i;
				b /=i;
				t /=i;
			}
			else i++;	
		}
		else i++;
	} while(i<t);
	return gcd;
}

int main(){
	int opcount = 0;
	printf("Enter values of a and b :\n");
	int a,b;
	scanf("%d%d",&a, &b);
	int result = msmethod(a,b,&opcount);
	printf("gcd of %d and %d is %d \nopcount: %d\n",a,b,result,opcount);
}