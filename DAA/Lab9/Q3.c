#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int linearprobe(int hashtable[],int m,int i){
	int j;
	for(j=i+1;j<m;j++){
		if(hashtable[j]==0)
			return j;
	}
	if(j==m)
			j = 0;
	return linearprobe(hashtable,m,j-1);
}

int main(){
	int n,m;
	printf("Enter the number of keys: ");
	scanf("%d",&n);
	printf("Enter the array size: ");
	scanf("%d",&m);
	int hashtable[m];
	for(int i=0;i<m;i++)
		hashtable[i] = 0;
	int ele;
	double alpha = n/m;
	for(int i=0;i<n;i++){
		printf("Enter the element: ");
		scanf("%d",&ele);
		int pos = ele%m;
		if(hashtable[pos] == 0)
			hashtable[pos] = ele;
		else{
			pos = linearprobe(hashtable,m,pos);
			hashtable[pos] = ele;
		}
	}
	for(int i=0;i<m;i++)
		printf("%d ",hashtable[i]);

	printf("NUMBER OF COMPARISONS IN SUCCESSFUL SEARCH : %f",(0.5*(1+(1/1-alpha))));
	printf("NUMBER OF COMPARISONS IN UNSUCCESSFUL SEARCH : %f",0.5*(1+(1/pow((1-alpha),2))));

}