#include <stdio.h>
int main() {
  float prices[10] = {0.75,1.00,1.25,1.50,1.75,2.00,2.25,2.50,2.75,3.00}; // fixed size array
  float avg, sum = 0;
  int length = sizeof(prices) / sizeof(prices[0]);


  for (int i = 0; i < length; i++) {
    sum += prices[i];
  }
  avg = sum / length;
  printf("The average price is: %.2f", avg);

    adding_to_array();
  return 0;
}

// This doesn't work
int adding_to_array() {
  int arr[10] = {1,2,3,4,5};
  printf("The first element is: %d\n", arr[0]);
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  arr[5] = 6;
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}