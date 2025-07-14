#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"

int main()
{
  char *name = "Hasan";
  char *nameCopy = malloc(sizeof(char) * (stringLength(name) + 1));

  printf("The length of the string %s is %d\n", name, stringLength(name));
  stringCopy(name, nameCopy);
  printf("Original - %s\nCopied - %s\n", name, nameCopy);

  free(nameCopy);

  return 0;
}