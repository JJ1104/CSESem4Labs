#include<stdio.h>

int fib(int n,int* opcount){
	(*opcount)++;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1,opcount) + fib(n-2,opcount);
}

int main(){
	int n,opcount = 0;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("%d\n",fib(n-1,&opcount));
	printf("Operation Count: %d",opcount);
}

