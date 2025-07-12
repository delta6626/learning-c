#include <stdio.h>

void *getPassword(int includeNumbers, int includeSpecialCharacters, char *generatedPassword){
  
};

int main()
{

  const char *characters = "abcdefghijklmnopqrstuvwxyz";
  const char *numbers = "0123456789";
  const char *specialCharacters = "*!@#$^&*.,`?><_-";
  char *generatedPassword;

  const int minLength = 8;
  int length;
  char includeSpecialCharacters = 'y';
  char includeNumbers = 'y';

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

  if (includeNumbers == 'y' && includeSpecialCharacters == 'y')
  {
    getPassword(1, 1, generatedPassword);
  }
  else if (includeNumbers == 'y' && includeSpecialCharacters == 'n')
  {
    getPassword(1, 0, generatedPassword);
  }
  else if (includeNumbers == 'n' && includeSpecialCharacters == 'y')
  {
    getPassword(0, 1, generatedPassword);
  }
  else if (includeNumbers == 'n' && includeSpecialCharacters == 'n')
  {
    getPassword(0, 0, generatedPassword);
  }
  else
  {
    printf("Invalid option. Exiting..\n");
    exit(-1);
  }

  return 0;
}