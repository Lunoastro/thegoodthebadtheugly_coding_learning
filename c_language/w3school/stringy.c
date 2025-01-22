#include <string.h> 
#include <stdio.h>

int main()
{
  char str1[12] = "Hello";
  char str2[12] = "World";
  char str3[12];
  int len;

  strcpy(str3, str1); // copy function
  printf("strcpy(str3, str1): %s\n", str3);

  
  strcat(str1, str2); //concatenation function
  printf("strcat(str1, str2): %s\n", str1);

  len = strlen(str1); // strlen does not include the null terminator \0 when counting
  printf("strlen(str1): %d\n", len);

  int compare = strcmp(str1, str2); // compare function
  printf("strcmp(str1, str2): %d\n", compare); // returns 0 if equal, char_difference if str1 > str2, -char_difference if str1 < str2
  return 0;
}