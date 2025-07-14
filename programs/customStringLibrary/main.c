#include <stdio.h>
#include "stringlib.h"

int main()
{
  char *name = "Hasan";
  printf("The length of the string %s is %d\n", name, stringLength(name));
  return 0;
}