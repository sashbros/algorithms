/*
    Code for counting strongly connected components in a directed, unweighted graph
    using DFS recursively two times as per the Kosaraju's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define init 1
#define wait 2
#define visi 3

int flag = 0;
int stack[MAX]; //this is the finish time stack, highest finish time on top
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
void DFS(int n, int adj[n][n], int state[n], int v) {
    int i;
    if(state[v]==init)
    {
        state[v] = visi;
        for (i=0; i<n; i++) {
            if (adj[v][i]==1 && state[i]==init) {
                DFS(n, adj, state, i);
            }
        }
        push(v);
    }
}
void secDFStraverse(int n, int adj[n][n], int state[n], int v) {
    int i;
    if (state[v] == init) {
        state[v] = visi;
        for (i=0; i<n; i++) {
            if (adj[v][i]==1 && state[i]==init) {
                flag=1;
                secDFStraverse(n, adj, state, i);
            }
        }
    }
}
int secDFS(int n, int adj[n][n], int state[n]) {
    int v, scc=0;
    while(!stackEmpty()) {
        v = pop();
        if (state[v] == visi) {
            continue;
        }
        if (state[v] == init) {
            flag = 0;
            secDFStraverse(n, adj, state, v);
            if (flag==1)
                scc++;
        }
    }
    return scc;
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

    for (i=0; i<n; i++) {
        if (state[i]==init) {
            DFS(n, adj, state, i);
        }
    }

    //taking transpose of the matrix
    int transAdj[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            transAdj[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j]==1) {
                transAdj[j][i] = 1;
            }
        }
    }
    for (i=0; i<n; i++) {
        state[i]=init;
    }
    printf("%d", secDFS(n, transAdj, state));
}
