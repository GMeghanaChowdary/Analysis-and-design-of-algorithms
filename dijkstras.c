#include <stdio.h>
#define INF 999  // Define a large value to represent infinity

// Function to find the shortest paths using Dijkstra's algorithm
void dijkstra(int source, int cost[20][20], int visited[20], int d[20], int n);

int main() {
    int i, j, n, source, cost[20][20], d[20], visited[20];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input the source node
    printf("\nEnter the source node: ");
    scanf("%d", &source);

    // Call Dijkstra's algorithm
    dijkstra(source, cost, visited, d, n);

    // Output the shortest paths
    printf("\nShortest paths from source node %d:\n", source);
    for (i = 1; i <= n; i++) {
        if (i != source) {
            if (d[i] == INF) {
                printf("No path to vertex %d\n", i);
            } else {
                printf("To vertex %d: %d\n", i, d[i]);
            }
        }
    }

    return 0;
}

void dijkstra(int source, int cost[20][20], int visited[20], int d[20], int n) {
    int i, j, min, u;

    // Initialize distances and visited array
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        d[i] = cost[source][i];
    }

    visited[source] = 1;
    d[source] = 0;

    // Iterate to find the shortest path to all vertices
    for (j = 2; j <= n; j++) {
        min = INF;
        u = -1;

        // Find the nearest unvisited vertex
        for (i = 1; i <= n; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break;  // No reachable unvisited vertex remains

        visited[u] = 1;

        // Update distances to neighboring vertices
        for (i = 1; i <= n; i++) {
            if (cost[u][i] != INF && !visited[i]) {
                if (d[i] > cost[u][i] + d[u]) {
                    d[i] = cost[u][i] + d[u];
                }
            }
        }
    }
}
