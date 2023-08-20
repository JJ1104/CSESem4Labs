#include<stdio.h>
#include<stdlib.h>

void createAdjMat(int** mat,int m){
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

void warshall(int** R,int **mat,int m){
	for(int k=0;k<m;k++){
		copy(R,mat,m);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				mat[i][j] = R[i][j] | R[i][k] & R[k][j];
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
	printf("Enter the adjacency matrix:\n");
	createAdjMat(mat,m);
	warshall(R,mat,m);
	printf("Transitive Closure\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}