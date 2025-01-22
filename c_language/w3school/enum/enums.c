#include <stdio.h>
enum temperature {
    cold = 10,
    warm = 20,
    hot = 30
};
// if no value is given then printf will print the index of the enum
// Note: If you give a value to the first enum then the rest of the enums will be incremented by 1

enum example {
    a = 1,
    b,
    c
};
int main() {
    enum temperature temp;
    temp = warm;
    printf("Temperature is %d\n", temp); // d is used for the enum because it is an integer
    enum example ex;
    ex = c;
    printf("Example is %d\n", ex);
    return 0;
}