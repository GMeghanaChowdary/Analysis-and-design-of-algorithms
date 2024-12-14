#include <stdio.h>
#include <limits.h>  // For INT_MAX

int ne = 1, min_cost = 0;  // Global variables to track edge count and minimum cost

// Function prototypes
int find_parent(int vertex, int parent[]);
void union_vertices(int u, int v, int parent[]);

int main() {
    int n, i, j, min, a, u, b, v, cost[20][20], parent[20];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("\nEnter the cost matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize the parent array
    for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    printf("\nThe edges of the spanning tree are:\n");

    // Kruskal's algorithm
    while (ne < n) {
        min = INT_MAX;

        // Find the edge with the smallest weight
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the parents of the vertices
        u = find_parent(u, parent);
        v = find_parent(v, parent);

        // Check if adding this edge forms a cycle
        if (u != v) {
            printf("Edge %d: (%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            union_vertices(u, v, parent);
        }

        // Mark the selected edge as processed
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);

    return 0;
}

// Function to find the parent of a vertex
int find_parent(int vertex, int parent[]) {
    while (parent[vertex]) {
        vertex = parent[vertex];
    }
    return vertex;
}

// Function to perform union of two vertices
void union_vertices(int u, int v, int parent[]) {
    parent[v] = u;
}
