#include <stdio.h>
int a = 10;
int b = 5;

int main()
{
    a += b; 
    printf("a += b: %d\n", a);
    a -= b; 
    printf("a -= b: %d\n", a);
    a *= b; 
    printf("a *= b: %d\n", a);
    a /= b; 
    printf("a /= b: %d\n", a);
    a %= b; 
    printf("a %%= b: %d\n", a);
    a &= b;  // bitwise AND
    printf("a &= b: %d\n", a);
    a |= b; // bitwise OR
    printf("a |= b: %d\n", a);
    a ^= b; // bitwise XOR
    printf("a ^= b: %d\n", a);
    a >>= b; // bitwise right shift by b
    printf("a >>= b: %d\n", a);
    a <<= b; // bitwise left shift by b
    printf("a <<= b: %d\n", a);

    return 0;
}