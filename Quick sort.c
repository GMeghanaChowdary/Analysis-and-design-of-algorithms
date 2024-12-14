#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 500

void qsort(int [], int, int);
int partition(int [], int, int);

int main() {
    int a[MAX], i, n;
    clock_t start, end;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Generate random array
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    // Display array before sorting
    printf("\nThe array elements before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    // Measure sorting time
    start = clock();
    qsort(a, 0, n - 1);
    end = clock();

    // Display sorted array
    printf("\n\nThe array elements after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    // Display time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime taken: %f seconds\n", time_taken);

    return 0;
}

void qsort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        qsort(a, low, j - 1);
        qsort(a, j + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot, i, j, temp;
    pivot = a[low];
    i = low + 1;
    j = high;

    while (1) {
        while (i <= high && a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j) {
            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            // Swap pivot and a[j]
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}
