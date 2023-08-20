#include<stdio.h>
#include<stdlib.h> 	

void Merge(int* B,int* C,int* A,int p,int q){
	int i=0,j=0,k=0;
	while(i<p && j<q){
		if(B[i] <= C[j]){
			A[k] = B[i];
			i++;
		}
		else{
			A[k] = C[j];
			j++;
		}
		k++;
	}
	if(i==p){
		while(j<q){
			A[k] = C[j];
			j++;
			k++;
		}
	}
	else{
		while(i<p){
			A[k] = B[i];
			i++;
			k++;
		}
	}
}

void MergeSort(int* A,int n,int* opc){
	(*opc)++;
	if(n > 1){
		int B_Size=n/2,C_Size=n-n/2,i = 0,k=0;
		int* B = (int*)calloc(B_Size,sizeof(int));
		int* C = (int*)calloc(C_Size,sizeof(int));
		while(i<n/2){
			B[i] = A[i];
			i++;
		}
		while(i<n){
			C[k] = A[i];
			k++;
			i++;
		}
		MergeSort(B,B_Size,opc);
		MergeSort(C,C_Size,opc);
		Merge(B,C,A,B_Size,C_Size);
	}
}

int main(){
	int n,opc=0;
	printf("Enter the size: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter elements ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	MergeSort(arr,n,&opc);
	printf("Sorted Array: ");
	for(int i =0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nOpcount: %d",opc);
}
