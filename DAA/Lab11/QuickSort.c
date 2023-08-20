#include<stdio.h>
#include<stdlib.h>

void swap(int* x,int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int* arr,int*source,int* dest,int l,int h){
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
			swap(&source[i],&source[j]);
			swap(&dest[i],&dest[j]);

		}
	}while(i<j);
	swap(&arr[l],&arr[j]);
	swap(&source[l],&source[j]);
	swap(&dest[l],&dest[j]);
	return j;
}

void QuickSort(int* arr,int*source,int*dest,int l,int h){
	if(l<h){
		int p = Partition(arr,source,dest,l,h);
		QuickSort(arr,source,dest,l,p-1);
		QuickSort(arr,source,dest,p+1,h);
	}
}