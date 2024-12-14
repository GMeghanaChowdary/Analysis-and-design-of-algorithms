#include <stdio.h>
#include <stdlib.h>

// Function prototype
void warshall(int adjacencyMatrix[10][10], int n);

int main() {
    int adjacencyMatrix[10][10], n;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Display adjacency matrix
    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Compute transitive closure using Warshall's Algorithm
    warshall(adjacencyMatrix, n);

    return 0;
}

void warshall(int adjacencyMatrix[10][10], int n) {
    // Perform Warshall's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 0 && 
                    adjacencyMatrix[i][k] == 1 && 
                    adjacencyMatrix[k][j] == 1) {
                    adjacencyMatrix[i][j] = 1;
                }
            }
        }
    }

    // Display the transitive closure (path matrix)
    printf("\nThe transitive closure (path matrix) is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
