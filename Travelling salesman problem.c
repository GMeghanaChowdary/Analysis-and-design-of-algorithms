#include<stdio.h>

int s, c[100][100], ver;
float optimum = 999, sum;

/* function to swap array elements */
void swap(int v[], int i, int j) {
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

/* recursive function to generate permutations */
void brute_force(int v[], int n, int i) {
    int j, sum1, k;

    // If we are at the end of the array, we have one permutation
    if (i == n) {
        if (v[0] == s) {
            // Print the permutation
            for (j = 0; j < n; j++) {
                printf("%d ", v[j]);
            }

            // Calculate the total sum for this permutation
            sum1 = 0;
            for (k = 0; k < n - 1; k++) {
                sum1 = sum1 + c[v[k]][v[k + 1]];
            }
            sum1 = sum1 + c[v[n - 1]][s]; // Return to source

            printf("sum = %d\n", sum1);
            if (sum1 < optimum) {
                optimum = sum1;  // Update optimum if this sum is lower
            }
        }
    } else {
        // Recursively explore the permutations starting at index i
        for (j = i; j < n; j++) {
            swap(v, i, j);  // Try the array with i and j swapped
            brute_force(v, n, i + 1);  // Recur for the next index
            swap(v, i, j);  // Swap them back to the original order
        }
    }
}

void nearest_neighbour(int ver) {
    int min, p, i, j, vis[20], from;

    // Initialize visited array
    for (i = 1; i <= ver; i++) {
        vis[i] = 0;
    }
    vis[s] = 1;
    from = s;
    sum = 0;

    // Find the nearest neighbor for each city
    for (j = 1; j < ver; j++) {
        min = 999;
        for (i = 1; i <= ver; i++) {
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0) {
                min = c[from][i];
                p = i;
            }
        }
        vis[p] = 1;  // Mark the city as visited
        from = p;
        sum = sum + min;  // Add the cost to the sum
    }

    // Return to the source city
    sum = sum + c[from][s];
}

int main() {
    int ver, v[100], i, j;

    // Input the number of cities (vertices)
    printf("Enter n : ");
    scanf("%d", &ver);

    // Input the cost matrix (adjacency matrix)
    printf("Enter cost matrix\n");
    for (i = 1; i <= ver; i++) {
        for (j = 1; j <= ver; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Input the source city
    printf("\nEnter source : ");
    scanf("%d", &s);

    // Initialize the array of cities (vertices)
    for (i = 0; i < ver; i++) {
        v[i] = i + 1;
    }

    // Call the brute force method to find the optimal solution
    brute_force(v, ver, 0);
    printf("\nOptimum solution with brute force technique is = %f\n", optimum);

    // Call the nearest neighbor method to find the solution
    nearest_neighbour(ver);
    printf("\nSolution with nearest neighbour technique is = %f\n", sum);

    // Calculate and print the approximation ratio
    printf("The approximation value is = %f %%", ((sum / optimum) - 1) * 100);

    return 0;
}
