#include<stdio.h>
#include<stdlib.h>

void input(int** mat,int m,int n){
	printf("Enter the elements: ");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}

void multiply(int** matA,int** matB,int** res,int r1,int c2,int r2,int* opcount){
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			res[i][j] = 0;
			for(int k=0;k<r2;k++){
				(*opcount)++;
				res[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
}

void printMat(int** mat,int m,int n){
	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int c1,r1,c2,r2,opcount = 0;
	printf("Enter the size of matrix A: ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the size of matrix B: ");
	scanf("%d %d",&r2,&c2);
	int** matA = (int**)calloc(r1,sizeof(int*));
	for(int i = 0;i<r1;i++){
		matA[i] = (int*)malloc(c1*sizeof(int));
	}
	int** matB = (int**)calloc(r2,sizeof(int*));
	for(int i = 0;i<r2;i++){
		matB[i] = (int*)malloc(c2*sizeof(int));
	}
	int** res = (int**)calloc(r1,sizeof(int*));
	for(int i = 0;i<r1;i++){
		res[i] = (int*)malloc(c2*sizeof(int));
	}

	input(matA,r1,c1);
	input(matB,r2,c2);

	printMat(matA,r1,c1);
	printMat(matB,r2,c2);

	multiply(matA,matB,res,r1,c2,r2,&opcount);

	printMat(res,r1,c2);

	printf("\nOperation Count: %d",opcount);
}