#include <stdio.h>
// variable types 
int a = 10; // Takes 2 or 4 bytes of memory
float b = 10.5; // Sufficient for storing 6-7 decimal digits. Takes up 4 bytes of memory
double c = 10.5; //Sufficient for storing 15 decimal digits. Takes up 8 bytes of memory
char d = 'A'; // Takes up 1 byte of memory
char e[] = "Hello"; // size is dependent on the number of characters in the string

int main()
{
    printf("Value of a is %d\n", a); // %d or %i for integer
    printf("Value of b is %f\n", b); // %f or %F for float (use %.xf for decimal precision)
    printf("Value of c is %lf\n", c); // %lf for double
    printf("Value of d is %c\n", d); // %c for char
    printf("Value of e is %s\n", e); // %s for string
    return 0;
}
