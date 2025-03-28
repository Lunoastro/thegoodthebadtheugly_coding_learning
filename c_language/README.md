
# Sources used

## For Theory

* [W3Schools](https://www.w3schools.com/c/index.php)
* [geeksforgeeks](https://www.geeksforgeeks.org)
* Brian “Beej Jorgensen” Hall
  * [Guide to C Programming](https://beej.us/guide/bgc/html/split/)
  * [Guide to Network Programming](https://beej.us/guide/bgnet/html/split/what-is-a-socket.html)

## For Practices

* [cryptohack](https://cryptohack.org/courses)

# Notes

## Imports

``#include <stdio.h>`` let's one work with input and output

``#include <stdbool.h>`` Allows for boolean operations (uses the %d signifier)

``#include <stdlib.h>`` Allows for memory management

``#include <string.h>``Allows for operations on strings

``#include <math.h>`` for mathematical operations like sqrt,ceil (rounds up),floor(rounds down) and pow (x to the power of y)

## various info

The precision of a floating point value indicates how many digits the value can have after the decimal point. The precision of float is six or seven decimal digits, while double variables have a precision of about 15 digits. Therefore, it is often safer to use double for most calculations - but note that it takes up twice as much memory as float (8 bytes vs. 4 bytes). [source](https://www.w3schools.com/c/c_data_types_numbers.php)

``const`` sets the variable unmutable and only gives the read permission to the variable.

Ternary operators are the same as they are in Java ``variable = (condition) ? expressionTrue : expressionFalse;``

The same can also be said for switches and for_loops as they also follow the same design.

Arrays seem to be immutable no matter if you declare it with `[num]` or `[]`
The & operator is used to get the address of a variable to which the user input will be saved to

An enum is a special type that represents a group of constants (unchangeable values).

## Functions

```c
#include <stdio.h>

void increment(int a)
{
    a++;
}

int main(void)
{
    int i = 10;

    increment(i);

    printf("i == %d\n", i);  //will print 10 even if 11 is expected
}
```

> It’s all about the fact that the expressions you pass to functions get copied onto their corresponding parameters. The parameter is a copy, not the original. ([Guide to C Programming](https://beej.us/guide/bgc/html/split/functions.html#functions))

## Memory

### Static Memory

Static memory is memory that is reserved for variables before the program runs. Allocation of static memory is also known as compile time memory allocation.

Example

```c
int students[20]; 
printf("%lu", sizeof(students)); // 80 bytes
```

But when the semester starts, it turns out that only 12 students (48 bytes)  are attending. Then you have wasted the space of 8 unused elements (32 bytes).


### Dynamic Memory

Dynamic memory is memory that is allocated after the program starts running. Allocation of dynamic memory can also be referred to as runtime memory allocation.

Dynamic memory does not belong to a variable, it can only be accessed with pointers.

To allocate dynamic memory, you can use the malloc() or calloc() functions. The malloc() and calloc() functions allocate some memory and return a pointer to its address.

```c
int *ptr1 = malloc(size);
int *ptr2 = calloc(amount, size); 
//  amount - Specifies the amount of items to allocate
// size - Specifies the size of each item measured in bytes
```

Note: The data in the memory allocated by malloc() is unpredictable. To avoid unexpected values, make sure to write something into the memory before reading it.

> `malloc()` allocates a memory block of given size (in bytes) and returns a pointer to the beginning of the block. `malloc()` doesn’t initialize the allocated memory. If you try to read from the allocated memory without first initializing it, then you will invoke undefined behavior, which usually means the values you read will be garbage values.
`calloc()` allocates the memory and also initializes every byte in the allocated memory to 0. If you try to read the value of the allocated memory without initializing it, you’ll get 0 as it has already been initialized to 0 by `calloc()`. Unlike `malloc()`, the `calloc()` function writes zeroes into all of the allocated memory. However, this makes `calloc()` slightly less efficient. Source
[geeksforgeeks](https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/)

The best way to allocate the right amount of memory for a data type is to use the sizeof operator:

```c
    int *ptr1, *ptr2;
    ptr1 = malloc(sizeof(*ptr1));
    ptr2 = calloc(1, sizeof(*ptr2));
```

Be careful: sizeof(*ptr1) tells C to measure the size of the data at the address. If you forget the * and write sizeof(ptr1) instead, it will measure the size of the pointer itself, which is the (usually) 8 bytes that are needed to store a memory address.

Note: The sizeof operator cannot measure how much dynamic memory is allocated. When measuring dynamic memory, it only tells you the size of the data type of the memory. For example, if you reserve space for 5 float values, the sizeof operator will return 4, which is the number of bytes needed for a single float value.

Let's use dynamic memory to improve the students example above.

As noted previously, we cannot use sizeof to measure how much memory was allocated, we have to calculate that by multiplying the amount of items by the size of the data type:
Example

```c
    int *students;
    int numStudents = 12;
    students = calloc(numStudents, sizeof(*students));
    printf("%d", numStudents * sizeof(*students)); // 48 bytes
```

### Stack Memory

Stack memory is a type of dynamic memory allocated for variables inside functions, which is freed when the function returns, and excessive recursion can lead to stack overflow (due to the function taking up too much stack memory).

### coding practices

It seems to be good coding practice to point the pointer to NULL to avoid using freed memory.