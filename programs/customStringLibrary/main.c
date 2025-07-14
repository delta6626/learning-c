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

  printf("The reverse of the string %s is %s\n", name, stringReverse(name));

  printf("The position of n in the the string Hasan is %d\n", stringCharacterPosition("Hasan", 'n'));

  free(nameCopy);

  return 0;
}