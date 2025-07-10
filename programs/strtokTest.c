#include <stdio.h>
#include <string.h>

int main()
{
  char string[] = "HEll0, W0RLD!";
  printf("%s", strtok(string, " "));

  return 0;
}
