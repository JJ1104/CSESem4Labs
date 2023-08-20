#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int tempvar = *a;
    *a = *b;
    *b = tempvar;
  }
  
void heapify(int* arr, int n, int i) {
    int greatest = i;
    int leftSide = 2 * i + 1;
    int rightSide = 2 * i + 2;
  
    if (leftSide < n && arr[leftSide] > arr[greatest])
      greatest = leftSide;
  
    if (rightSide < n && arr[rightSide] > arr[greatest])
      greatest = rightSide;
  
    if (greatest != i) {
      swap(&arr[i], &arr[greatest]);
      heapify(arr, n, greatest);
    }
}

void topdown(int* arr,int n){
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i >= 2)
		heapify(arr,i+1,i/2-1);
	}

}


int main(){
	int n = 5;
	int* arr = (int*)calloc(n,sizeof(int));
  
	topdown(arr,n);

    printf("Max Heap is \n");
   	for(int i=0;i<n;i++){
   		printf("%d ",arr[i]);
   	}
}