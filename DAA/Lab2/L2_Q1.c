#include<stdio.h>

int min(int a,int b){
	if(a > b)
		return b;
	return a;
}

int main(){
	int m,n;
	int t;
	printf("Enter the first number: ");
	scanf("%d",&m);
	printf("Enter the second number: ");
	scanf("%d",&n);
	t = min(m,n);
	int opc = 0;
	while(1){
		opc++;
		if(m%t == 0){
			if(n%t == 0)
				break;
		}
		t--;
	}
	printf("GCD of %d and %d is %d",m,n,t);
	printf("\nOperation Count: %d",opc);
	return 0;
}