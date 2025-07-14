// stringlib - My implementation of some common string functions from <string.h>

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