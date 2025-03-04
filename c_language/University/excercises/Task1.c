#include <stdio.h>
#include <stdlib.h>


 /*
  Task 1
A string can be compressed by replacing a (sub)sequence of consecutive identical character by the length of the sequence and the character.
For example, the compression version of the string”AAABBAAAA” is ”3A2B4A”, where ”3A” stands for three consecutive ”A”s, ”2B” for 
two consecutive ”B”s and ”4A” for four consecutive ”A”s.
*/

// 1.1: What are the compressed versions for strings”XXXXXXXX”,”ABCDEF”and”XXXXYYYY”?
// Answer: 8X, 1A1B1C1D1E1F, 4X4Y
// 1.2: Given a string of n characters, what is the minimum number and the maximum number of characters that are compressed?
// Answer: The minimum number of characters that are compressed is 2 and the maximum number of characters that are compressed is n/2.


// 1.3: Write the C function void compression(char string[], int n) in C that takes a string with n characters as input and prints the compressed version.
void compression(char string[],int n){
    int count = 1; // There will be at least one character
    for (int i = 0; i < n; i++){
        if (string[i] == string[i+1]){ // If the next character is the same as the current character
            count++; // Increase the count
        } else { // otherwise
            printf("%d%c", count, string[i]); // Print the count and the character
            count = 1; // Reset the count
        }
    }
}


// Task 2 Consider an array A with n integers and an integer t. The task is to find if there exist two integers in A whose sum is equal to t.
/*
2.1: Write a pseudocode algorithm that returns 1 if the sum of two integers in A is equal to t, returns 0 otherwise. 
Determine and explain the number of sum operation in your solution.
Pseudocode:
1. Sort the array A in an ascending order
2. Set left = 0 and right = n - 1
3. While left < right
4. If A[left] + A[right] == t
5. Return 1 

*/

//2.2: Write the C function int T(int A[], int n, int t) that returns 1 if there exist two integers in A whose sum is equal to t, returns 0 otherwise.
int T(int A[], int length, int sum){
    int left = 0;
    int right = length - 1;
    while (left < right){
        if (A[left] + A[right] == sum){
            return 1;
        } else if (A[left] + A[right] < sum){
            left++;
        } else {
            right--;
        }
    }
    return 0;
}






/*
Task 3
3.1: Write a pseudocode algorithm that returns 1 if there exist two integers in A whose sum is equal to t, returns 0 otherwise. Determine and explain the number of accesses made to the integers of array A in your solution. Can you reduce the number of accesses to make your solution more efficient?
3.2: Write the C function int TSort(int A[], int n, int t) that returns 1 if there exist two integers in A whose sum is equal to t, returns 0 otherwise.
*/
// [1,2,3,4,5] length = 5, sum = 7
int Tsort(int A[],int length, int sum){
    int left = 0;
    int right = length - 1;
    while (left < right){
        if (A[left] + A[right] == sum){
            return 1;
        } else if (A[left] + A[right] < sum){
            left++;
        } else {
            right--;
        }
    }
    return 0;
}
/*
Task 4
A subarray is a sequence of contiguous elements of an array. Write a C function int zeroSubarray(int A[], int n) that takes an array A of n integers and returns 1 if it is possible to find a subarray 
where the sum over the integers in the subarray is equal to zero. Otherwise, the function returns 0.
 */


 int main(){
    char exampleT1[] = "ABCDEF";
    printf("Compressed version of %s is: ", exampleT1);
    compression(exampleT1, 8);
    printf("\n");
    return 0;
 }