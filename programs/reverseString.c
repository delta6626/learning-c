#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  const int MAX_SIZE = 50;
  char *userInput = malloc(MAX_SIZE * sizeof(char));
  char *reversedString = malloc(MAX_SIZE * sizeof(char));

  if (userInput == NULL || reversedString == NULL)
  {
    printf("Failed to allocate memory. Exiting..\n");
    exit(-1);
  }

  printf("Type something: ");
  fgets(userInput, MAX_SIZE, stdin);

  for (int i = 0; i < strlen(userInput); i++)
  {
    *(reversedString + i) = userInput[strlen(userInput) - 1 - i];
  }

  *(reversedString + MAX_SIZE) = '\0';

  printf("The reversed string is %s\n", reversedString);

  free(userInput);
  free(reversedString);

  return 0;
}