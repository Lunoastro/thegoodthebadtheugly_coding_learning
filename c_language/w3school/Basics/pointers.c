#include <stdio.h>


int main()
{
    int num = 43;    
    int* ptr = &num;  // A pointer variable that just stores the memory address of num
    // int *ptr = &num; Also works
    
    printf("%d\n", num); // Output the value of num (43)
    printf("%d\n", *ptr); // Output the value using the pointer variable with the De-referencing operator (*)
    

    // Output the memory address of num  1. with the reference operator (&) 2. with the pointer variable (ptr)
    printf("%p\n", &num);
    printf("%p\n", ptr);
    return 0;
}