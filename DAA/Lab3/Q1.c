#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,temp;
	int opcount = 0;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter the array elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			opcount++;
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nOperation Count: %d",opcount);
	return 0;
}