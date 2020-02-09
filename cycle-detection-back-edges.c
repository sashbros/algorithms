/*
    Code for detecting a cycle in a directed, unweighted graph
    using DFS and Adjacency Matrix.
    This is also the code for detecting the number of
    BACK EDGES in a directed, unweighted graph.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define init 1
#define wait 2
#define visi 3

int stack[MAX];
int top = -1;
void push(int item) {
    top++;
    stack[top] = item;
}
int pop() {
    int item = stack[top];
    top--;
    return item;
}
int peek() {
    return stack[top];
}
int stackEmpty() {
    if (top==-1) {
        return 1;
	}
    else {
        return 0;
	}
}
//returns 1 if there is a cycle
int DFS(int n, int adj[n][n], int state[n], int v) {
    int i;
    push(v);
    state[v] = wait;
    while(!stackEmpty()) {
		v = pop();
		if (state[v]==init) {
			//printf("%d ", v+1); //printing DFS
			state[v] = visi;
		}
		for (i=0; i<n; i++) {
			if (adj[v][i]==1 && state[i]==init) {
				push(i);
                state[v] = wait;
            }
            if (adj[v][i]==1 && state[i]==wait)
                return 1;
		}
    }
    return 0;
}
int main() {
    int n; //no. of vertices
    int i, j, edge, origin, dest;
    scanf("%d %d", &n, &edge);
    int adj[n][n]; //adjacency matrix
    int state[n]; //state of the vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    //nodes are from 1 to N
    for (i=0; i<edge; i++) {
        scanf("%d %d", &origin, &dest);
        adj[origin-1][dest-1] = 1;
    }
    for (i=0; i<n; i++) {
        state[i]=init;
    }
    
    if (DFS(n, adj, state, 0) == 1) //0 being the start point
        printf("YES");
    else
        printf("NO");
    return 0;
}

