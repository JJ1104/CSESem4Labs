#include<stdio.h>
#include<stdlib.h>

void swap(int* x,int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int* arr,int l,int h){
	int p = arr[l];
	int i = l;
	int j = h+1;
	do{	
		do{
			i++;
		}while(arr[i] < p);
		do{
			j--;
		}while(arr[j] > p);
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}while(i<j);
	swap(&arr[l],&arr[j]);
	return j;
}

void QuickSort(int* arr,int l,int h,int* opc){
	(*opc)++;
	if(l<h){
		int p = Partition(arr,l,h);
		QuickSort(arr,l,p-1,opc);
		QuickSort(arr,p+1,h,opc);
	}
}

int main(){
	int n,opc = 0;
	printf("Enter the size: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter elements ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1,&opc);
	printf("Sorted Array: ");
	for(int i =0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nOpcount: %d",opc);
}	