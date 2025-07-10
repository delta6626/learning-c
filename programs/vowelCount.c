#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

int main()
{

  int count = 0;
  char *userInput = malloc(sizeof(char) * MAX_SIZE);

  if (userInput == NULL)
  {
    printf("An error occured while allocating memory. Exiting..\n");
    exit(-1);
  }

  printf("Enter a word or sentence: ");
  fgets(userInput, MAX_SIZE, stdin);

  for (int i = 0; i < strlen(userInput); i++)
  {
    char lowerCased = tolower(*(userInput + i));
    if (lowerCased == 'a' || lowerCased == 'e' || lowerCased == 'i' || lowerCased == 'o' || lowerCased == 'u')
    {
      count++;
    }
  }

  printf("Found %d vowels in total.\n", count);

  free(userInput);

  return 0;
}