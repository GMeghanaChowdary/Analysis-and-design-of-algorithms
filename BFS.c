#include <stdio.h>

void BFS(int adjacency_matrix[20][20], int source, int visited[20], int num_vertices);

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

    // Mark the source node as visited and perform BFS
    visited[source] = 1;
    BFS(adjacency_matrix, source, visited, num_vertices);

    // Print the reachability of each node
    for (i = 1; i <= num_vertices; i++) {
        if (visited[i] != 0) {
            printf("\nNode %d is reachable", i);
        } else {
            printf("\nNode %d is not reachable", i);
        }
    }

    return 0;
}

void BFS(int adjacency_matrix[20][20], int source, int visited[20], int num_vertices) {
    int queue[20], front = 0, rear = -1, u, v;

    // Add the source node to the queue
    queue[++rear] = source;

    // Perform BFS
    while (front <= rear) {
        u = queue[front++]; // Dequeue a node

        // Visit all adjacent nodes
        for (v = 1; v <= num_vertices; v++) {
            if (adjacency_matrix[u][v] == 1 && visited[v] == 0) {
                queue[++rear] = v;  // Enqueue the adjacent node
                visited[v] = 1;     // Mark it as visited
            }
        }
    }
}
