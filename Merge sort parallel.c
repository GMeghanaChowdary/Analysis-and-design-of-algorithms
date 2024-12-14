#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

#define MAX 100

void mergeSort(std::vector<int> &arr, int low, int high);
void merge(std::vector<int> &arr, int low, int mid, int high);

int main() {
    int n;
    clock_t start, end;
    std::vector<int> arr(MAX);

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Generate random elements
    std::cout << "Elements of the array before sorting:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        std::cout << arr[i] << "\t";
    }

    // Sort and measure time
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    // Display sorted array
    std::cout << "\nElements of the array after sorting:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "\t";
    }

    // Time taken
    double time_taken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nThe time taken = " << time_taken << " seconds\n";

    return 0;
}

void mergeSort(std::vector<int> &arr, int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;

        // Recursive merge sort
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge sorted subarrays
        merge(arr, low, mid, high);
    }
}

void merge(std::vector<int> &arr, int low, int mid, int high) {
    int h = low, j = mid + 1, i = low;
    std::vector<int> temp(arr.size());

    // Merge in sorted order
    while (h <= mid && j <= high) {
        if (arr[h] <= arr[j]) {
            temp[i++] = arr[h++];
        } else {
            temp[i++] = arr[j++];
        }
    }

    // Copy remaining elements
    while (h <= mid) {
        temp[i++] = arr[h++];
    }
    while (j <= high) {
        temp[i++] = arr[j++];
    }

    // Copy back to original array
    #pragma omp parallel for
    for (int k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
}
