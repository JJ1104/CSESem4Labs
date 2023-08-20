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