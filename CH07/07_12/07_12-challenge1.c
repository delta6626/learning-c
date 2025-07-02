#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* main program */
int main()
{
	// variable declaration
	char command[20];

	while (1)
	{
		printf("Command: ");
		fgets(command, 20, stdin);

		for (int x = 0; x < strlen(command); x++)
		{
			if (command[x] == '\n')
			{
				command[x] = '\0';
			}

			command[x] = toupper(command[x]);
		}

		printf("Processing command '%s'", command);
		putchar('\n');

		if (strcmp(command, "QUIT") == 0)
		{
			break;
		}
	}

	return 0;
}
