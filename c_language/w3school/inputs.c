#include <stdio.h>

int main()
{
    int op1, op2;
    printf("Enter the numbers (space seperated): ");
    scanf("%d %d", &op1, &op2);
    printf("The sum of %d and %d is %d\n", op1, op2, op1 + op2);
}