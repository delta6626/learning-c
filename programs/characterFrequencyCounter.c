#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

int main()
{

  char *sentence = malloc(sizeof(char) * MAX_SIZE);
  int *countArray = calloc(256, sizeof(int));
  int sentenceLength;

  if (sentence == NULL || countArray == NULL)
  {
    printf("An error occured while allocating memory. Exiting..\n");
    exit(-1);
  }

  printf("Enter word or sentence: ");
  fgets(sentence, MAX_SIZE, stdin);

  sentenceLength = strlen(sentence);

  if (sentence[sentenceLength - 1] == '\n')
  {
    sentence[sentenceLength - 1] = '\0';
  }

  for (int i = 0; i < sentenceLength; i++)
  {
    countArray[(unsigned int)sentence[i]] += 1;
  }

  printf("Character Frequencies:\n");

  for (int i = 0; i < 256; i++)
  {
    if (countArray[i] > 0)
    {
      printf("'%c': %2d\n", i, countArray[i]);
    }
  }

  free(sentence);
  free(countArray);

  return 0;
}