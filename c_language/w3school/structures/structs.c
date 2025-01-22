#include <stdio.h> 
#include <string.h>

struct person {
    char name[50];
    int age;
    float salary;
};

int main() {
    struct person p1;
    printf("Enter name: ");
    fgets(p1.name, sizeof(p1.name), stdin);
    p1.name[strlen(p1.name) - 1] = '\0'; // Remove the newline character
    printf("Enter age: ");
    scanf("%d", &p1.age);
    printf("Enter salary: ");
    scanf("%f", &p1.salary);
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Salary: %.2f\n", p1.salary);
    return 0;
}