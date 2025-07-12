#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getPassword(int length, char *generatedPassword)
{
  srand((unsigned int)time(NULL));

  const char *characters = "abcdefghijklmnopqrstuvwxyz!@#$^&*.-_<>+=0123456789";

  for (int x = 0; x < length; x++)
  {
    generatedPassword[x] = characters[rand() % strlen(characters)];
  }

  generatedPassword[length] = '\0';
  printf("Your password is: %s\n", generatedPassword);
}

int main()
{
  const int minLength = 8;
  int length;

  printf("Enter the length of the required password: ");
  scanf("%d", &length);

  if (length < minLength)
  {
    printf("Length should be at least %d characters.\n", minLength);
    return 1;
  }

  char *generatedPassword = malloc(sizeof(char) * (length + 1));

  if (generatedPassword == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(-1);
  }

  getPassword(length, generatedPassword);

  free(generatedPassword);

  return 0;
}