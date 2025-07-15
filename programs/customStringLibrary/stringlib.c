// stringlib - My implementation of some common string functions from <string.h>

#include <stdlib.h>
#include <ctype.h>

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

void stringReverse(char *string)
{
  int left = 0;
  int right = stringLength(string) - 1;

  char temp;

  while (left < right)
  {
    temp = *(string + left);
    *(string + left) = *(string + right);
    *(string + right) = temp;
    left++;
    right--;
  }
}

int stringCharacterPosition(char *string, char character)
{
  for (int x = 0; x < stringLength(string); x++)
  {
    if (string[x] == character)
    {
      return x;
    }
  }

  return -1; // Not found
}

int charToCode(char character)
{
  int x = character;
  return x;
}

void stringUpper(char *string)
{
  for (int x = 0; x < stringLength(string); x++)
  {
    *(string + x) = toupper(*(string + x));
  }
}

void stringLower(char *string)
{
  for (int x = 0; x < stringLength(string); x++)
  {
    *(string + x) = tolower(*(string + x));
  }
}