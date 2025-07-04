#include <stdio.h>
#include <stdlib.h>

/*
Simple malloc:
Write a program that dynamically allocates memory for an array of 10 integers.
Ask the user to input values and then print them.
*/

int main()
{

  int *buffer = malloc(sizeof(int) * 10);
  if (buffer == NULL)
  {
    printf("An error occured in reserving memory.\n");
    exit(0);
  }
  else
  {
    // Get the values
    for (int i = 0; i < 10; i++)
    {
      printf("Enter your number #%d: ", i + 1);
      scanf("%d", buffer + i);
    }

    // Print the values

    for (int i = 0; i < 10; i++)
    {
      printf("You entered: %d\n", *(buffer + i));
    }

    free(buffer);
  }

  return 0;
}