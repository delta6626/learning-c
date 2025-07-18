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

  stringReverse(nameCopy);
  printf("The reverse of the string %s is %s\n", name, nameCopy);

  stringReverse(nameCopy);

  printf("The position of n in the the string Hasan is %d\n", stringCharacterPosition("Hasan", 'n'));

  stringUpper(nameCopy);

  printf("The name %s in uppercase is %s\n", name, nameCopy);

  stringLower(nameCopy);

  printf("The name %s in lowercase is %s\n", name, nameCopy);

  char *concatenatedNames = stringConcat(name, nameCopy);

  printf("The concatenation of %s and %s is %s\n", name, nameCopy, concatenatedNames);

  free(nameCopy);
  free(concatenatedNames);

  return 0;
}