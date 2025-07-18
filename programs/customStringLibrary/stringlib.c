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

int stringIsNumeric(char *string)
{
  for (int x = 0; x < stringLength(string); x++)
  {
    int code = charToCode(string[x]);
    if (code < 48 || code > 57)
    {
      return -1;
    }
  }

  return 1;
}

int stringIsAlpha(char *string)
{
  for (int x = 0; x < stringLength(string); x++)
  {
    int code = charToCode(string[x]);

    if (!((code >= 65 && code <= 90) || (code >= 97 && code <= 122)))
    {
      return -1;
    }
  }

  return 1;
}

char *stringConcat(char *string1, char *string2)
{
  int l1 = stringLength(string1);
  int l2 = stringLength(string2);

  char *concatenatedString = malloc(sizeof(char) * (l1 + l2 + 1));

  if (!concatenatedString)
  {
    return NULL;
  }

  for (int x = 0; x < l1; x++)
  {
    concatenatedString[x] = string1[x];
  }

  for (int x = 0; x < l2; x++)
  {
    concatenatedString[l1 + x] = string2[x];
  }

  concatenatedString[l1 + l2] = '\0';

  return concatenatedString;
}

int stringStartsWith(char *string, char *substring)
{
  int substringLength = stringLength(substring);
  for (int x = 0; x < substringLength; x++)
  {
    if (string[x] != substring[x])
    {
      return -1;
    }
  }

  return 1;
}