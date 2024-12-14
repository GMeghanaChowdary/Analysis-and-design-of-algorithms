#include <stdio.h>
#define MAX 50

// Global variables
int profits[MAX], weights[MAX], n;

// Function prototypes
int knapsack(int i, int capacity);
int max(int a, int b);

int main() {
    int capacity, optimalSolution;

    // Input number of objects
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    // Input weights
    printf("\nEnter the weights of the objects:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weights[i]);
    }

    // Input profits
    printf("\nEnter the profits of the objects:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &profits[i]);
    }

    // Input knapsack capacity
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Compute the optimal solution
    optimalSolution = knapsack(1, capacity);

    // Output the result
    printf("\nThe optimal solution is: %d\n", optimalSolution);

    return 0;
}

// Recursive function for the 0/1 Knapsack problem
int knapsack(int i, int capacity) {
    // Base case: If we reach the last item
    if (i == n) {
        return (weights[n] > capacity) ? 0 : profits[n];
    }

    // If the current item cannot be included
    if (weights[i] > capacity) {
        return knapsack(i + 1, capacity);
    }

    // Return the maximum of including or excluding the current item
    return max(knapsack(i + 1, capacity), knapsack(i + 1, capacity - weights[i]) + profits[i]);
}

// Function to find the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}
