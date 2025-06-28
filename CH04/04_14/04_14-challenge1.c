#include <stdio.h>
#include <stdlib.h>

int main()
{
	// variable declarations
	char command;
	int done = 0;
	/* main program loop */

	while (!done)
	{
		// prompt for input
		printf("Enter command:");
		command = getchar();

		switch (command)
		{
		case 'R':
		case 'r':
			puts("move right");
			break;
		case 'L':
		case 'l':
			puts("move left");
			break;
		case 'B':
		case 'b':
			puts("move back");
			break;
		case 'Q':
		case 'q':
			puts("Goodbye!");
			done = 1;
			break;
		case 'H':
		case 'h':
		case '?':
			puts("Valid commands: R, L, B, Q, H and ?");
			break;
		default:
			puts("I don't know that command");
			break;
		}
		while (getchar() != '\n')
			;
	}

	return 0;
}