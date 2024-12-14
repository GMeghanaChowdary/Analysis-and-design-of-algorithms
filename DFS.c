#include <stdio.h>
#include <stdlib.h>

void DFS(int adjacency_matrix[20][20], int node, int visited[20], int num_vertices);

int main() {
    int num_vertices, adjacency_matrix[20][20], visited[20], source;
    int i, j;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= num_vertices; i++) {
        for (j = 1; j <= num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    // Initialize visited array
    for (i = 1; i <= num_vertices; i++) {
        visited[i] = 0;
    }

    // Input the source node
    printf("\nEnter the source node: ");
    scanf("%d", &source);

    // Perform DFS starting from the source node
    DFS(adjacency_matrix, source, visited, num_vertices);

    // Check if all nodes are visited
    for (i = 1; i <= num_vertices; i++) {
        if (visited[i] == 0) {
            printf("\nGraph is not connected\n");
            return 0;
        }
    }

    printf("\nGraph is connected\n");
    return 0;
}

void DFS(int adjacency_matrix[20][20], int node, int visited[20], int num_vertices) {
    int neighbor;

    // Mark the current node as visited
    visited[node] = 1;

    // Visit all unvisited neighbors
    for (neighbor = 1; neighbor <= num_vertices; neighbor++) {
        if (adjacency_matrix[node][neighbor] == 1 && visited[neighbor] == 0) {
            DFS(adjacency_matrix, neighbor, visited, num_vertices);
        }
    }
}
