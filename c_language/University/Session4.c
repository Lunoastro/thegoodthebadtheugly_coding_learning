#include <stdio.h>
#include <stdlib.h>





int linearSearch(int arr[], int length, int toFind){
    for (int i = 0; i < length; i++){
        if (arr[i] == toFind){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int length, int toFind){
    int left = 0;
    int right = length - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == toFind){ // 
            return mid;
        }
        if (arr[mid] < toFind){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50,60,70};
    int toFind = 30;
    int result2 = binarySearch(arr, 7, toFind);
    if (result2 == -1){
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result2);
    }
    return 0;
}