#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void findIndegree(int adjacencyMatrix[10][10], int indegree[10], int n);
void topologicalSort(int n, int adjacencyMatrix[10][10]);

int main() {
    int adjacencyMatrix[10][10], n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Display adjacency matrix
    printf("\nThe adjacency matrix is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Perform topological sort
    topologicalSort(n, adjacencyMatrix);
    
    return 0;
}

// Function to find the indegree of each node
void findIndegree(int adjacencyMatrix[10][10], int indegree[10], int n) {
    for (int j = 1; j <= n; j++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += adjacencyMatrix[i][j];
        }
        indegree[j] = sum;
    }
}

// Function to perform topological sort
void topologicalSort(int n, int adjacencyMatrix[10][10]) {
    int stack[20], indegree[20], top = -1, result[100], k = 1;

    findIndegree(adjacencyMatrix, indegree, n);

    // Push nodes with indegree 0 onto the stack
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    // Process nodes
    while (top != -1) {
        int u = stack[top--];
        result[k++] = u;

        for (int v = 1; v <= n; v++) {
            if (adjacencyMatrix[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    stack[++top] = v;
                }
            }
        }
    }

    // Display topological order
    printf("\nTopological sequence is:\n");
    for (int i = 1; i < k; i++) {
        printf("%d\t", result[i]);
    }
}
