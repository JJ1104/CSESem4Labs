#include<stdio.h>
#include<string.h>

int main(){
	char text[20];
	char pattern[20];
	printf("Enter the text: ");
	scanf("%s",text);
	printf("Enter the pattern: ");
	scanf("%s",pattern);
	int n = strlen(text);
	int m = strlen(pattern);
	int opcount = 0,found = 0;
	for(int i=0;i<=n-m;i++){
		int count=0;
		int k = i;
		for(int j=0;j<m;j++){
			opcount++; 
			if(text[k] == pattern[j]){
				k++;	
				count++;
			}
		}	
		if(count == m){
			found = 1;
			break;
		}
	}
	if(found)
		printf("String Found");
	else
		printf("String not found");
	printf("\nOperation Count: %d",opcount);

}