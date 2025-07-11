#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200

char *toLower(char *string)
{
  for (int i = 0; i < strlen(string); i++)
  {
    *(string + i) = tolower(*(string + i));
  }

  return string;
}

int main()
{

  char *sentence = malloc(sizeof(char) * MAX_SIZE);
  char *sentenceReversed = malloc(sizeof(char) * MAX_SIZE);
  int length;

  if (sentence == NULL || sentenceReversed == NULL)
  {
    printf("Error allocating memory. Exiting..\n");
    exit(-1);
  }

  printf("Enter a word or sentence: ");
  fgets(sentence, MAX_SIZE, stdin);

  length = strlen(sentence);

  if (sentence[length - 1] == '\n')
  {
    sentence[length - 1] = '\0';
    length--;
  }

  for (int i = 0; i < length; i++)
  {
    *(sentenceReversed + i) = sentence[length - 1 - i];
  }

  sentenceReversed[length] = '\0';

  if (strcmp(toLower(sentenceReversed), toLower(sentence)) == 0)
  {
    printf("Palindrome\n");
  }
  else
  {
    printf("Not a palindrome.\n");
  }

  free(sentence);
  free(sentenceReversed);

  return 0;
}