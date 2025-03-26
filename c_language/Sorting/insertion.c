#include <stdio.h> 

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i]; // store the current element
        int j = i - 1; // look at the previous element
        while (j >= 0 && arr[j] > temp){  // if the previous element is greater than the current element
            arr[j + 1] = arr[j];
            j--; 
        }
        arr[j+1] = temp; //swap temp to the swapped position
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 6, 3,4, 70,30,48,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
    
}