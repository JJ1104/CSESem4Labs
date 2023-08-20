#include<stdio.h>
#include<stdlib.h>
#include "LL.c"

int main(){
	int n,m;
	printf("Enter the number of keys: ");
	scanf("%d",&n);
	printf("Enter the array size: ");
	scanf("%d",&m);
	Node hashtable[m];
	for(int i=0;i<m;i++)
		hashtable[i] = NULL;
	int ele;
	double alpha = n/m;
	for(int i=0;i<n;i++){
		printf("Enter the element: ");
		scanf("%d",&ele);
		int pos = ele%m;
		InsertRear(&hashtable[pos],ele);
	}
	for(int i=0;i<m;i++)
		display(hashtable[i]);

	printf("NUMBER OF COMPARISONS IN SUCCESSFUL SEARCH : %f",(1+(alpha/2)));
	printf("NUMBER OF COMPARISONS IN UNSUCCESSFUL SEARCH : %f",alpha);

}