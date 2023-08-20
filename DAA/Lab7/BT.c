#include <stdio.h>
#include <stdlib.h>

typedef struct BST * Node;
typedef struct BST
{
    int data;
    Node LChild;
    Node RChild;
}BST;

Node getnode()
{
    return ((Node)malloc(sizeof(BST)));
}

void insert(Node* root,int val){
    Node head = *root;
    Node temp = getnode();
    Node parent = NULL;

    temp->data = val;
    temp->RChild = temp->LChild = NULL;
    if(head == NULL){
        head = temp;
        *root = head;
        return;
    }
    while(head != NULL){
        parent = head;
        if(val > head->data){
            head = head->RChild;
        }
        else{
            head = head->LChild;
        }
    }
    if(val > parent->data){
        parent->RChild = temp;
    }
    else{
        parent->LChild = temp;
    }
    return;
}

void create_BST(Node* root){
    int val;
    while(1){
        printf("Enter the value you want to insert(-1 to exit) : ");
        scanf("%d",&val);
        if(val == -1){break;}
        insert(root,val);
    }
}