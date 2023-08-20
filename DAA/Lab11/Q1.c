#include<stdio.h>
#include<stdlib.h>
#include "QuickSort.c"
#define INF 1000

void createweightmat(int** mat,int v){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}

void findcycle(int**mat,int v,int start,int desti,int i,int j,int* cycle){
		if(i==6 && start ==6){
			printf("hey i j %d %d\n",i,j);
		}
		if(mat[i][j] == INF){
			*cycle = 0;
			return;
		}
		else{
			
			i = j;
			if(start==6){
				printf("start %d i %d j %d\n",start,i,j);
			}
			if(start == j){
				*cycle = 1;
				return;
			}
			for(int k=i;k<v;k++){
				if(*cycle){break;}
				findcycle(mat,v,start,desti,i,k,cycle);
			}	
		}
}


void kruskal(int* weight,int* source,int* dest,int** mat,int v,int e){
	int k=0;
	for(int i=0;i<v;i++){
		for(int j=i;j<v;j++){
			if(mat[i][j] != 0 && mat[i][j] != INF){
				weight[k] = mat[i][j];
				source[k] = i;
				dest[k] = j;

				k++;							
			}
		}
	}
	QuickSort(weight,source,dest,0,e-1);
	int nedges = 0;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			mat[i][j] = INF;
		}
	}
	k=0;
	while(nedges != v-1){
		mat[source[k]][dest[k]] = weight[k];
		mat[dest[k]][source[k]] = weight[k];
		int cycle = 0;
		findcycle(mat,v,source[k],dest[k],source[k],dest[k],&cycle);
		if(cycle){
			mat[source[k]][dest[k]] = INF;
		}
		else{
			nedges++;
		}
		k++;
	}
}

int main(){
	int v,e;
	printf("Enter the the number of vertices and number of edges: ");
	scanf("%d %d",&v,&e);
	int** mat = (int**)calloc(v,sizeof(int*));
	for(int i=0;i<v;i++){
		mat[i] = (int*)calloc(v,sizeof(int));
	}
	int* weight = (int*)calloc(e,sizeof(int));
	int* source = (int*)calloc(e,sizeof(int));
	int* dest = (int*)calloc(e,sizeof(int));
	printf("Enter the weight matrix:\n");
	createweightmat(mat,v);
	kruskal(weight,source,dest,mat,v,e);
	printf("Minimum Spanning Tree\n");
	// for(int i=0;i<v;i++){
	// 	for(int j=0;j<v;j++){
	// 		printf("%d ",mat[i][j]);
	// 	}
	// 	printf("\n");
	// }

}
