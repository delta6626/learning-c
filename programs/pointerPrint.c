/*
Print Elements of an Array Using Pointers:
Declare an array of integers and use a pointer to print each element, one per line.
*/

#include <stdio.h>

int main()
{

  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *ptr = numbers;
  for (int i = 0; i < 10; i++)
  {
    printf("The element at index %d is %d\n", i, *(ptr + i));
  }

  return 0;
}