#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

int main()
{

  int *nums = malloc(MAX_SIZE * sizeof(int));

  if (nums == NULL)
  {
    printf("Error occured while allocating memory. Exiting..\n");
    exit(-1);
  }

  int i = 0;

  while (i < MAX_SIZE)
  {
    printf("Enter number %d: ", i + 1);
    scanf("%d", nums + i);
    i++;
  }

  int max = INT_MIN;
  int secondMax = INT_MIN;

  for (int i = 0; i < MAX_SIZE; i++)
  {
    if (*(nums + i) > max)
    {
      max = *(nums + i);
    }
  }

  for (int i = 0; i < MAX_SIZE; i++)
  {
    if (*(nums + i) != max && *(nums + i) > secondMax)
    {
      secondMax = *(nums + i);
    }
  }

  if (secondMax == INT_MIN)
  {
    printf("No minimum found. All numbers are same.\n");
  }
  else
  {
    printf("The second larges number is: %d\n", secondMax);
  }

  free(nums);

  return 0;
}