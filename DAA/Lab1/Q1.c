#include<stdio.h>
#include<stdlib.h>

typedef struct BST* Node;

typedef struct BST{
	int data;
	Node RChild,LChild;
}BST;

Node getnode(){
	Node temp = (Node)malloc(sizeof(BST));
	return temp;
}

void createBST(Node* Tree){
	Node cur = *Tree;
	Node parent = *Tree;
	int item;
	if(parent == NULL){
		printf("Enter the root: ");
		scanf("%d",&item);
		Node temp = getnode();
		temp->data = item;
		temp->RChild = temp->LChild = NULL;
		*Tree = temp;
	}
	while(1){
		Node cur = *Tree;
		Node parent = *Tree;
		printf("Enter the value to insert:" );
		scanf("%d",&item);
		if(item == -1){break;}
		while(cur){
			parent = cur;
			if(cur->data < item){
				cur = cur->RChild;
			}
			else{
				cur = cur->LChild;
			}
		}
		Node temp = getnode();
		temp->data = item;
		temp->RChild = temp->LChild = NULL;
		if(parent->data < item){
			parent->RChild = temp;
		}
		else{
			parent->LChild = temp;
		}
	}
}

void inorder(Node root){
	if(root){
		inorder(root->LChild);
		printf("%d ",root->data);
		inorder(root->RChild);
	}
}

void preorder(Node root){
    if(root){
        printf("%d ",root->data);
        preorder(root->LChild);
        preorder(root->RChild);
    }
}

void postorder(Node root){
    if(root){
        postorder(root->LChild);
        postorder(root->RChild);
        printf("%d ",root->data);
    }
}

void searchBST(Node* Tree,int key){
	Node parent = *Tree;
	Node cur = *Tree;
	while(cur){
		parent = cur;
		if(cur->data == key){
			printf("Key Found");
			return;
		}
		else if(cur->data < key){
			cur = cur->RChild;
		}
		else{
			cur = cur->LChild;
		}
	}
	Node temp = getnode();
	temp->data = key;
	temp->RChild = temp->LChild = NULL;
	if(parent->data < key){
		parent->RChild = temp;
	}
	else{
		parent->LChild = temp;
	}
	printf("Key inserted");
	return;
}

int main(){
	Node Tree = NULL;
	createBST(&Tree);
	inorder(Tree);
	printf("\n");
	// searchBST(&Tree,70);
	preorder(Tree);
	printf("\n");
	postorder(Tree);
}
