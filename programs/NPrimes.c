#include <stdio.h>

void outputPrime(int n)
{
  int isPrime = 1;
  for (int x = 2; x < n; x++)
  {
    if (n % x == 0)
    {
      isPrime = 0;
      break;
    }
  }

  if (isPrime)
  {
    printf("%d\n", n);
  }
}

int main()
{

  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 0 || num == 0 || num == 1)
  {
    printf("The number should be greater than 1\n");
    exit(-1);
  }

  printf("Prime numbers till %d:\n", num);

  for (int x = 2; x <= num; x++)
  {
    outputPrime(x);
  }

  return 0;
}