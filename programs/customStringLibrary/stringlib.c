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