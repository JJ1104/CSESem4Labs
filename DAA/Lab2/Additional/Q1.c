#include<stdio.h>

void tower(int disk,char source,char aux,char dest,int* opcount){
	(*opcount)++;
	if(disk == 1)
		printf("Move the disk from %c to %c\n",source,dest);
	else{
		tower(disk-1,source,dest,aux,opcount);
		printf("Move the disk from %c to %c\n",source,dest);
		tower(disk-1,aux,source,dest,opcount);
	}
} 

int main(){
	int n,opcount=0;
	char source,aux,dest;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	printf("Enter the source,auxiliary and destination: ");
	scanf(" %c %c %c",&source,&aux,&dest);
	tower(n,source,aux,dest,&opcount);
	printf("Operation Count: %d",opcount);
	return 0;
}