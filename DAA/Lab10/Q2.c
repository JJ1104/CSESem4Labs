#include<stdio.h>
#include<stdlib.h>

void createweightmat(int** mat,int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}

void copy(int**R,int**mat,int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			R[i][j] = mat[i][j];
		}
	}
}

int min(int a,int b){
	return a<b?a:b;
}

void floyd(int** R,int **mat,int m){
	for(int k=0;k<m;k++){
		copy(R,mat,m);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				mat[i][j] = min(R[i][j],R[i][k]+R[k][j]);
			}
		}
	}
}

int main(){
	int m;
	printf("Enter the the number of vertices: ");
	scanf("%d",&m);
	int** mat = (int**)calloc(m,sizeof(int*));
	for(int i=0;i<m;i++){
		mat[i] = (int*)calloc(m,sizeof(int));
	}
	int** R = (int**)calloc(m,sizeof(int*));
	for(int i=0;i<m;i++){
		R[i] = (int*)calloc(m,sizeof(int));
	}
	printf("Enter the weight matrix:\n");
	createweightmat(mat,m);
	floyd(R,mat,m);
	printf("Distance Matrix \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}