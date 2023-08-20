#include<stdio.h>
#include<stdlib.h>
#include "BT.c"

void countNodes(Node root,int* count,int* opc){
	(*opc)++;
	if(root){
		countNodes(root->LChild,count,opc);
		(*count)++;
		countNodes(root->RChild,count,opc);
	}
}

int main(){
	int count = 0,opc=0;
	Node Tree = NULL;
	Tree = create_BT(Tree,1);
	countNodes(Tree,&count,&opc);
	printf("Number of Nodes: %d\n",count);
	printf("Opcount: %d",opc);
	return 0;
}
