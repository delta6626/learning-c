#include <stdio.h>
#include "stringlib.h"

int main()
{
  char *name = "Hasan";
  char *nameCopy;

  printf("The length of the string %s is %d\n", name, stringLength(name));
  stringCopy(name, nameCopy);
  printf("Original - %s\nCopied - %s\n", name, nameCopy);

  return 0;
}