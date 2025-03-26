#include <stdio.h>

// Extended Euclidean Algorithm to find modular inverse
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}
// Function to find modular inverse
int modInverse(int a, int mod) {
    int x, y;
    int g = gcdExtended(a, mod, &x, &y);
    
    if (g != 1) {
        printf("Modular inverse doesn't exist\n");
        return -1; // Inverse doesn't exist if gcd(a, mod) ≠ 1
    }
    
    return (x % mod + mod) % mod; // Ensure the result is positive
}

// TASK: Determine which of the given integers (14, 6, 11) has a square root modulo 29, and find the smaller of the two possible square roots.
int main() {
    int mod = 29;
    int a = 14, b = 6, c = 11;
    int a_inv = modInverse(a, mod);
    int b_inv = modInverse(b, mod);
    int c_inv = modInverse(c, mod);
    
    printf("The modular inverse of %d is %d\n", a, a_inv);
    printf("The modular inverse of %d is %d\n", b, b_inv);
    printf("The modular inverse of %d is %d\n", c, c_inv);
    
    return 0;
}
