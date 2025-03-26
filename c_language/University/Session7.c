/* 
An array A[1..n] is balanced if
▶ the sum of the elements in the first half is no more than double and no less than half the sum of the elements in the second half, and
▶ the first and second half are balanced.
Give an algorithm that determines if an array is balanced. 
Use the substitution method to prove the asymptotic complexity of the algorithm.
*/

#include <stdio.h> // for printf 


int sum(int arr[], int start, int end){
    int sum = 0;
    for (int i = start; i <= end; i++){
        sum += arr[i];
    }
    return sum;
}

int isBalanced(int arr[], int start, int end){
    if (start == end){
        return 1;
    }
    int mid = (start + end) / 2;
    int sum1 = sum(arr, start, mid);
    int sum2 = sum(arr, mid + 1, end);
    if (sum1 <= 2 * sum2 && sum1 >= sum2 / 2){
        return isBalanced(arr, start, mid) && isBalanced(arr, mid + 1, end);
    }
    return 0;
}

int main(){
    int arr[] = {1, 2, 3,5, 7};
    int result = isBalanced(arr, 0, 4);
    if (result){
        printf("Array is balanced\n");
    } else {
        printf("Array is not balanced\n");
    }
    return 0;
}