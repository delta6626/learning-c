#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void *getPassword(char includeNumbers, char includeSpecialCharacters, int length, char *generatedPassword)
{

  srand((unsigned int)time(NULL));

  const char *characters = "abcdefghijklmnopqrstuvwxyz";
  const char *numbers = "0123456789";
  const char *specialCharacters = "*!@#$^&*.,`?><_-";

  char n = '\0';
  char s = '\0';

  for (int x = 0; x < length; x++)
  {
    *(generatedPassword + x) = characters[rand() % strlen(characters)];
  }

  printf("Your password is: %s\n", generatedPassword);
};

int main()
{

  char *generatedPassword;

  const int minLength = 8;
  int length;
  char includeSpecialCharacters;
  char includeNumbers;

  printf("Enter the length of the required password: ");
  scanf("%d", &length);

  if (length < minLength)
  {
    printf("Length should at least be %d characters.\n", minLength);
    exit(-1);
  }

  printf("Include numbers (y/n)? : ");
  scanf("%c", includeNumbers);

  printf("Include special characters (y/n)? : ");
  scanf("%c", includeSpecialCharacters);

  generatedPassword = malloc(sizeof(char) * length);

  getPassword(includeNumbers, includeSpecialCharacters, length, generatedPassword);

  return 0;
}