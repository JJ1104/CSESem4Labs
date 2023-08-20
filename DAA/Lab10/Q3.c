#include<stdio.h>
#include<stdlib.h>

void input(int* weight,int* value,int items){
	for(int i=1;i<=items;i++){
		printf("Enter the weight of item %d: ",i);
		scanf("%d",&weight[i]);
		printf("Enter the value of item %d: ",i);
		scanf("%d",&value[i]);
	}
}

int max(int a,int b){
	return a>b?a:b;
}

void knapsackDP(int** kpmat,int capacity,int items,int* weight,int* value,int* optimalsubset){
	for(int i=1;i<=items;i++){
		for(int j=1;j<=capacity;j++){
			if(j >= weight[i])
				kpmat[i][j] = max(kpmat[i-1][j],value[i]+kpmat[i-1][j-weight[i]]);
			else
				kpmat[i][j] = kpmat[i-1][j];
		}
	}
	int j = capacity;
	int k=0;
	for(int i=items;i>0;i--){
		if(kpmat[i][j] != kpmat[i-1][j]){
			optimalsubset[k++] = i;
			j = j - weight[i];
		}
		else
			continue;
	}
}

int main(){
	int capacity,items;
	printf("Enter the number of items and capacity of KP: ");
	scanf("%d %d",&items,&capacity);
	int* weight = (int*)calloc(items+1,sizeof(int));
	int* value = (int*)calloc(items+1,sizeof(int));
	int* optimalsubset = (int*)calloc(items,sizeof(int));
	int** kpmat = (int**)calloc(items+1,sizeof(int*));
	for(int i=0;i<items+1;i++)
		kpmat[i] = (int*)calloc(capacity+1,sizeof(int));
	input(weight,value,items);
	knapsackDP(kpmat,capacity,items,weight,value,optimalsubset);
	printf("KDP Matrix:\n");
	for(int i=0;i<=items;i++){
		for(int j=0;j<=capacity;j++){
			printf("%d\t",kpmat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Optimal Subset: \n");
	for(int i=0;optimalsubset[i]!=optimalsubset[i+1];i++){
		printf("%d ",optimalsubset[i]);
	}
}