#include <stdio.h>
#include <stdlib.h>

typedef struct BT * Node;
struct BT
{
    int data;
    Node LChild;
    Node RChild;
};

Node getnode()
{
    return ((Node)malloc(sizeof(struct BT)));
}

Node create_BT(Node root,int data)
{
    int x;
    if(data!=-1)
    {
        Node temp=getnode();
        temp->data=data;

        printf("\n Enter LChild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->LChild=create_BT(temp->LChild,x);

        printf("\n Enter RChild of %d : \t",temp->data);
        scanf("%d",&x);
        temp->RChild=create_BT(temp->RChild,x);
        return temp;
    }
    return NULL;
}

int max(int a,int b){
	return a>b?a:b;
}

int height(Node root){
	if(root)
		return max(height(root->LChild),height(root->RChild))+1;
}

void findDia(Node root,int* dia){
	int temp = 0;
	if(root){
		int L = height(root->LChild);
		int R = height(root->RChild);
		temp = L+R+1;
		if(temp > *dia)
			*dia = temp;
	}
	else{
		return;
	}
	findDia(root->LChild,dia);
	findDia(root->RChild,dia);
}

int main(){
	int dia = 0;
	Node Tree = NULL;
	Tree = create_BT(Tree,0);
	findDia(Tree,&dia);
	printf("\nDiameter is %d\n",dia);
}

//1 2 -1 -1 3 4 -1 -1 5 -1 -1 6 -1 7 -1 8 9 10 -1 -1 11 -1 -1 12 -1 -1
//1 2 3 -1 -1 4 5 6 -1 -1 7 -1 -1 -1 8 -1 9 10 -1 -1 11 -1 12 -1 -1 13 -1 14 -1 -1
