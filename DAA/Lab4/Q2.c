#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	int data;
	int push_order;
	int pop_order;
	int visited;
}element;

typedef struct Stack{
	element* stack;
	int tos;
}Stack;



void push(Stack* ps,int ele){
	ps->stack[++tos].visited = 1;
	ps->stack[++tos].data = ele;
	ps->stack[++tos].push_order++;
}

int pop(Stack* ps){
	if(ps->tos == -1){
		return -1;
	}
	else{
		ps->stack[++tos].pop_order++;
		return ps->stack[tos--].data;
	}
}

// void dfs(int adj[][3],int u,Stack* ps){
// 	ps->stack[u].visited = 1;
// 	ps->stack[u].push_order++;
// 	for(int i=0;i<n;i++){
// 		if(adj[u][i] != ps->stack[i].visited)
// 			dfs(adj,v,ps);
// 	}
// }

// void init(int adj[][3],int n,Stack* ps){
// 	for(int i=0;i<n;i++){
// 		ps->stack[i].visited = 0;
// 	}
// 	for(int i=0;i<n;i++){
// 		dfs(adj,i,ps);
// 	}
// }

int main(){
	Stack *ps,s;
	ps = &s;
	ps->tos = -1;
	ps->stack = (element*)malloc(n*sizeof(element));
	for(int i=0;i<n;i++){
		ps->stack[i].visited = 0;
		ps->stack[i].push_order = 0;
		ps->stack[i].pop_order = 0;

	}
	int adj[3][3] ={{0,1,1},
					{1,0,1},
					{1,1,0}}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ps->tos == -1){
				push(ps,i+1);
			}
			if(adj[i][j] == 1 && ps->stack[j].visited = 0){
				push(ps,j+1);
			}
			if(ps->tos == n-1 || ps)
		}	
		
	}

}
