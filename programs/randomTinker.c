#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  unsigned int seed = (unsigned int)time(NULL);
  srand(seed);

  for (int x = 1; x <= 10; x++)
  {
    int y = (rand() % 100);
    printf("%d\n", y);
  }

  return 0;
}