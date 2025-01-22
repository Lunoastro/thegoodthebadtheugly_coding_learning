
# Sources used

[W3Schools](https://www.w3schools.com/c/index.php)

# Notes

## Imports

``#include <stdio.h>`` let's one work with input and output

``#include <stdbool.h>`` Allows for boolean operations (uses the %d signifier)

``#include <string.h>``Allows for operations on strings

``#include <math.h>`` for mathematical operations like sqrt,ceil (rounds up),floor(rounds down) and pow (x to the power of y)

## Infos

The precision of a floating point value indicates how many digits the value can have after the decimal point. The precision of float is six or seven decimal digits, while double variables have a precision of about 15 digits. Therefore, it is often safer to use double for most calculations - but note that it takes up twice as much memory as float (8 bytes vs. 4 bytes). [source](https://www.w3schools.com/c/c_data_types_numbers.php)

``const`` sets the variable unmutable and only gives the read permission to the variable.

Ternary operators are the same as they are in Java ``variable = (condition) ? expressionTrue : expressionFalse;``

The same can also be said for switches and for_loops as they also follow the same design.

Arrays seem to be immutable no matter if you declare it with `[num]` or `[]`
The & operator is used to get the address of a variable to which the user input will be saved to
