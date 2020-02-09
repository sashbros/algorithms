/*
    Code for single source shortest path in a directed/non-directed, weighted graph
    i.e., minimum distance from a source node to all other nodes using
    Dijkstra's Algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define init 1
#define visi 2
#define infi 999

int minimum(int n, int dist[n], int state[n]) {
    int min = infi;
    int minIndex = 0;
    for (int i=0; i<n; i++) {
        if (dist[i]<min && dist[i]!=0 && state[i]==init) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Dijkstra(int n, int adj[n][n], int dist[n], int state[n], int v) {
    int i;
    int flag=0;
    while(1) {
        int min = minimum(n, dist, state);
        state[min] = visi;
        for (i=0; i<n; i++) {
            if (state[i] == init) {
                if (dist[i] > dist[min] + adj[min][i]) {
                    dist[i] = dist[min] + adj[min][i];
                }
            }
        }
        for (i=0; i<n; i++) {
            if (state[i] == init)
                flag=0;
            else
                flag=1;
        }
        if (flag == 1)
            break;
    }
    
}

int main() {
    int n; //no. of vertices
    int i, j, edge, origin, dest, dis;
    scanf("%d %d", &n, &edge);
    int adj[n][n]; //adjacency matrix
    int state[n]; //state of the vertex
    int dist[n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = infi;
        }
    }
    for (i=0; i<n; i++) {
        adj[i][i] = 0;
    }
    //nodes are from 1 to N
    for (i=0; i<edge; i++) {
        scanf("%d %d %d", &origin, &dest, &dis);
        adj[origin-1][dest-1] = dis;
        adj[dest-1][origin-1] = dis;
    }
    for (i=0; i<n; i++) {
        state[i]=init;
    }
    int v; //vertice to be set as source
    scanf("%d", &v);
    v=v-1;
    for (i=0; i<n; i++) {
        if (i==v)
            dist[i] = 0;
        else if (adj[v][i]<infi)
            dist[i] = adj[v][i];
        else
            dist[i] = infi;
    }
    
    state[v] = visi;
    Dijkstra(n, adj, dist, state, v);

    for (i=0; i<n; i++) {
        if (dist[i]!=0)
            printf("%d ", dist[i]);
    }

    return 0;
}

