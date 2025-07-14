// stringlib - My implementation of some common string functions from <string.h>

#include <stdlib.h>

int stringLength(char *string)
{
  int l = 0;
  while (*(string + l) != '\0')
  {
    l++;
  }
  return l;
}

void stringCopy(char *source, char *destination)
{
  for (int i = 0; i < stringLength(source) + 1; i++)
  {
    *(destination + i) = *(source + i);
  }
}

char *stringReverse(char *string)
{
  int x = 0;
  int y = stringLength(string);

  char *reversedString = malloc(sizeof(char) * (y + 1));
  if (!reversedString)
    return NULL;

  while (y > 0)
  {
    reversedString[x] = string[y - 1];
    y--;
    x++;
  }

  reversedString[x] = '\0';
  return reversedString;
}
