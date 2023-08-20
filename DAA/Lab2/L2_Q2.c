#include<stdio.h>

int isPrime(int n,int* opc){
	for(int i=2;i<n;i++){
		(*opc)++;
		if(n==2)
			return 1;
		else{
			if(n%i == 0)
				return 0;
		}
	}
	return 1;
}

int min(int a,int b){
	if(a > b)
		return b;
	return a;
}

int middleSchoolAlgo(int m,int n,int* opc){
	
	int gcd = 1;
	int t = min(m,n);
	int i = 2;
	while(i<t){
		(*opc)++;
		if(m == 1 && n == 1)
			break;

		if(isPrime(i,opc)){
			if(m%i == 0 && n%i == 0){
				gcd *= i;
				m = m/i;
				n = n/i;
				t = t/i;
			}
			else{
				i++;
			}	
		}
		else{
			i++;
		}
	}
	return gcd;
}


int main(){
	int m,n;
	int opc = 0;
	printf("Enter the first number: ");
	scanf("%d",&m);
	printf("Enter the second number: ");
	scanf("%d",&n);
	int gcd = middleSchoolAlgo(m,n,&opc);
	printf("GCD of %d and %d is %d",m,n,gcd);
	printf("\nOperation Count: %d",opc);
	return 0;
}