#include <stdio.h>

int main()
{
    /*
    int op1, op2;
    printf("Enter the numbers (space seperated): ");
    scanf("%d %d", &op1, &op2);
    printf("The sum of %d and %d is %d\n", op1, op2, op1 + op2);
    */
   /*
    for strings you don't need to use & operator
    thoughts: we don't need to use & operator for strings because strings are already an array of characters
    */
    

    char fullName[30];

    printf("Type your full name: \n");
    fgets(fullName, sizeof(fullName), stdin);

    printf("Hello %s", fullName);

}