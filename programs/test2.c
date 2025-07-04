/*
String duplication :
Write a program that takes a string from the user,
dynamically allocates just enough memory to store it,
and makes a copy of the string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  char tempString[100];
  printf("Enter a sentence not longer than 100 characters: \n");
  fgets(tempString, 100, stdin);

  char *buffer = malloc(sizeof(char) * (strlen(tempString) + 1));
  for (int i = 0; i < strlen(tempString); i++)
  {
    *(buffer + i) = tempString[i];
  }
  *(buffer + strlen(tempString)) = '\0';

  printf("Copied string: %s\n", buffer);
  free(buffer);

  return 0;
}