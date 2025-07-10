#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  srand((unsigned int)time(NULL));

  const int maxGuesses = 10;
  int totalGuesses = 0;
  int guess;
  int number = (rand() % 100) + 1;

  printf("Welcome!\n");
  printf("I have chosen number between 1 - 100.\n");
  printf("You have %d tries to guess the number.\n", maxGuesses);

  while (totalGuesses != maxGuesses)
  {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    totalGuesses += 1;

    if (guess == number)
    {
      printf("Great job! You won in %d tries!\n", totalGuesses);
      exit(0);
    }
    else if (guess > number)
    {
      printf("Guess lower!\n");
    }
    else
    {
      printf("Guess higher!\n");
    }
  }

  printf("Yikes! You lost. No worries though, try again.\n");

  return 0;
}