#include <stdio.h>

int ne = 1, min_cost = 0;

void main() {
    int n, i, j, min, cost[20][20], a, u, b, v, source, visited[20];

    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Get the cost matrix
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    // Get the root node
    printf("Enter the root node: ");
    scanf("%d", &source);
    visited[source] = 1;  // Mark the source as visited

    printf("\nMinimum cost spanning tree is:\n");

    // Prim's algorithm to find the minimum spanning tree
    while (ne < n) {
        min = 999;  // Start with a large value for min
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                // Find the smallest edge connecting a visited node to a non-visited node
                if (cost[i][j] < min && visited[i] != 0 && visited[j] == 0) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        // If an edge is found, include it in the MST
        if (visited[a] == 1 && visited[b] == 0) {
            printf("Edge %d: (%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            visited[b] = 1;  // Mark the destination node as visited
        }

        // Set the cost of the selected edge to a large value to avoid re-selection
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
