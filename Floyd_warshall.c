#include <stdio.h>
#include <omp.h>

#define MAX 10

void floyd(int a[MAX][MAX], int n);
int min(int a, int b);

int main() {
    int n, a[MAX][MAX], i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(a, n);

    return 0;
}

void floyd(int a[MAX][MAX], int n) {
    int d[MAX][MAX], i, j, k;

    // Initialize distance matrix d with the cost matrix a
    #pragma omp parallel for collapse(2)
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            d[i][j] = a[i][j];
        }
    }

    // Floyd-Warshall algorithm with parallelization
    #pragma omp parallel for collapse(2)
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Printing the distance matrix
    printf("\nThe distance matrix is:\n");
    #pragma omp parallel for collapse(2)
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
