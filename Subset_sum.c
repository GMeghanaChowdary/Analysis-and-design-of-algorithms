#include <stdio.h>

// Function prototypes
void subset(int current_sum, int index, int remaining_sum);

// Global variables
int x[10], w[10], d, count = 0;

int main() {
    int i, n, sum = 0;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements in ascending order
    printf("\nEnter the elements in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Input the target sum
    printf("\nEnter the target sum: ");
    scanf("%d", &d);

    // Compute the total sum of the elements
    for (i = 0; i < n; i++) {
        sum += w[i];
    }

    // Check if the total sum is less than the target
    if (sum < d) {
        printf("No solution\n");
        return 0;
    }

    // Perform backtracking to find subsets
    subset(0, 0, sum);

    // If no subsets found
    if (count == 0) {
        printf("No solution\n");
    }

    return 0;
}

// Backtracking function to find subsets
void subset(int current_sum, int index, int remaining_sum) {
    int i;

    // Include the current element in the subset
    x[index] = 1;

    // If the current subset sum equals the target
    if (current_sum + w[index] == d) {
        printf("\n\nSubset %d:\n", ++count);
        for (i = 0; i <= index; i++) {
            if (x[i] == 1) {
                printf("%d\t", w[i]);
            }
        }
    }
    // If the current sum with the next element is less than or equal to the target
    else if (current_sum + w[index] + w[index + 1] <= d) {
        subset(current_sum + w[index], index + 1, remaining_sum - w[index]);
    }

    // Exclude the current element from the subset
    if (current_sum + remaining_sum - w[index] >= d && current_sum + w[index] <= d) {
        x[index] = 0;
        subset(current_sum, index + 1, remaining_sum - w[index]);
    }
}
