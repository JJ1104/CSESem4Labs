#include<stdio.h>
#include<stdlib.h>
#include "BT.c"

int max(int a,int b){
	return a>b?a:b;
}

int height(Node root){
	if(root){
		return max(height(root->LChild),height(root->RChild))+1;
	}
}

void balfac(Node root){
	if(root){
		int L = height(root->LChild);
		int R = height(root->RChild);
		int temp = L-R;
		printf("Data: %d and Balance Factor: %d\n",root->data,temp);
	}
	else{
		return;
	}
	balfac(root->LChild);
	balfac(root->RChild);

}


int main(){
	Node Tree = NULL;
	create_BST(&Tree);
	balfac(Tree);
}