#include <stdio.h>

int main()
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  putchar('\n');

  int isPrime = 1;

  for (int i = 2; i < n - 1; i++)
  {
    if (n % i == 0)
    {
      isPrime = 0;
      printf("The number %d is not prime\n", n);
      break;
    }
  }

  if (isPrime == 1)
  {
    printf("The number %d is prime\n", n);
  }

  return 0;
}