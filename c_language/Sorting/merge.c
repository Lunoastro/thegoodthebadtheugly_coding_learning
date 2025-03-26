#include <stdio.h>
#include <stdlib.h>
/*
Mostly copied from https://www.geeksforgeeks.org/merge-sort/
with modifications to comments and techniques I have learned previously
*/


void merge(int* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Size of leftArr[]
    int n2 = right - mid; // Size of rightArr[]

    
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));
    if (leftArr == NULL || rightArr == NULL) {fprintf(stderr, "Memory allocation failed\n");exit(1);}

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i]; // leftArr[] = arr[left..mid]
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j]; // rightArr[] = arr[mid+1..right]

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) { // this loop will run until either i or j reaches the end of their respective arrays
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    free(leftArr);
    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    free(rightArr);
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int* arr, int left, int right) {
    if (left < right) { // Base case: if left < right, then the array has more than one element
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right); // Merge both subarrays
    }
    // If it reaches here, then the array is already sorted (base case)
}

// mmemonic: 2 times mergeSort + merge = 2T(n/2) + O(n) = O(nlogn)
// Space complexity: O(n) for temporary arrays
// Time complexity: O(nlogn) for all cases (worst, average, best)

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Invalid array size\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill the array with random numbers
    printf("Filling the array with random numbers...\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000000; // Random numbers between 0 and 99
    }
    
      // Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}