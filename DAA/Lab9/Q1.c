#include<stdio.h>
#include<string.h>

void shifttable(int shift[],char pattern[]){
	int m = strlen(pattern);
	for(int i=0;i<27;i++){
		shift[i] = m;
	}
	for(int i=0;i<m-1;i++){
		if(pattern[i] == ' ')
			shift[26] = m-i-1;
		else
			shift[pattern[i]-65] = m-i-1;
	}
}


int horspool(char text[],char pattern[],int shift[]){
	int opcount = 0;
	int n = strlen(text);
	int m = strlen(pattern);
	int i=m-1,j=0,flag=0;
	while(i<n){
		int k = i,p=m-1;
		opcount++;
		while(pattern[p] == text[k] && j<m){
			opcount++;
			j++;
			k--;
			p--;
			if(j<m)
				flag = 1;
			else
				flag =0;
		}
		if(flag){
			opcount++;
			flag = 0;
		}
		if(j!=m){
			if(text[i] == ' ')
				i += shift[26];
			else
				i += shift[text[i]-65];
		}
		else{
			printf("STRING FOUND\n");
			break;
		}
	}
	return opcount-1;
}

int main(){
	int shift[27];
	char pattern[20],text[30];
	printf("Enter the text: ");
	gets(text);
	printf("Enter the pattern: ");
	gets(pattern);
	shifttable(shift,pattern);
	int opc = horspool(text,pattern,shift);
	printf("Number of KEY COMPARISONS : %d",opc);

}