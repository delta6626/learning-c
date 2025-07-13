#include <stdio.h>

int main()
{

  enum PowerStatus
  {
    ON = 1,
    OFF = 0
  };

  enum PowerStatus s1 = ON;
  printf("Power status of your machine : %d\n", s1);

  return 0;
}