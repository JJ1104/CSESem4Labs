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

int balfac(Node root){
	if(root){
		int L = height(root->LChild);
		int R = height(root->RChild);
		return L-R;
	}
}

Node leftrotate(Node x){
	Node y = x->RChild;
	Node z = y->LChild;

	y->LChild  = x;
	x->RChild = z;

	return y;
}

Node rightrotate(Node x){
	Node y = x->LChild;
	Node z = y->RChild;

	y->RChild  = x;
	x->LChild = z;

	return y;
}

Node insert_AVL(Node root,int val){
	if(root == NULL){
		Node temp = getnode();
		temp->data = val;
		temp->RChild = temp->LChild = NULL;
		return temp;
	}
	if(val < root->data){
		root->LChild = insert_AVL(root->LChild,val);
	}
	else if(val > root->data){
		root->RChild = insert_AVL(root->RChild,val);
	}
	else
		return root;

	int balfact = balfac(root);

	if(balfact < -1 && val > root->RChild->data){
		return leftrotate(root);
	}
	if(balfact > 1 && val < root->LChild->data){
		return rightrotate(root);
	}
	if(balfact > 1 && val > root->LChild->data){
		root->LChild = leftrotate(root->LChild);
		return rightrotate(root);
	}
	if(balfact < -1 && val < root->RChild->data){
		root->RChild = rightrotate(root->RChild);
		return leftrotate(root);
	}

	return root;
}

Node create_AVL(Node root){
	int val;
    while(1){
        printf("Enter the value you want to insert(-1 to exit) : ");
        scanf("%d",&val);
        if(val == -1){break;}
        root=insert_AVL(root,val);
    }
    return root;
}

void inorder(Node root){
	if(root){
		inorder(root->LChild);
		printf("%d ",root->data);
		inorder(root->RChild);
	}
}

int main(){
	Node Tree = NULL;
	Tree = create_AVL(Tree);
	inorder(Tree);
}