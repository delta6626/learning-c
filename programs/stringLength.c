#include <stdio.h>

int stringLength(char *string)
{
  int x = 0;
  while (*(string + x) != '\0')
  {

    x += 1;
  }

  return x;
}

int main()
{

  char *name = "Hasan";

  printf("The length of the string %s is %d\n", name, stringLength(name));

  return 0;
}