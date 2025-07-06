#include <stdio.h>
#include <string.h>

int main()
{

	/*
	Fetch user input
	*/

	const char filename[] = "hello.txt";
	char username[50];
	printf("Enter your name: ");
	fgets(username, 50, stdin);

	/*
	Write to file
	*/

	FILE *fileWriter = fopen(filename, "w");
	if (fileWriter == NULL)
	{
		printf("Error creating file!");
		exit(1);
	}
	else
	{
		fputs(username, fileWriter);
		// Close the file after writing
		fclose(fileWriter);
	}

	for (int i = 0; i < strlen(username); i++)
	{
		if (username[i] != '\n')
		{
			putchar(username[i]);
		}
	}

	printf(" has written to this file.\n");

	/*
	Read from file
	*/

	FILE *fileReader = fopen(filename, "r");

	if (fileReader == NULL)
	{
		printf("Error reading from file!\n");
		exit(1);
	}

	char readUsername[50];
	int x = 0;
	char c;
	while (1)
	{
		c = fgetc(fileReader);
		if (c == '\n')
		{
			readUsername[x] = '\0';
			break;
		}
		else
		{
			readUsername[x] = c;
			x += 1;
		}
	}

	// Close the file

	fclose(fileReader);

	printf("The string '%s' was written to the file by %s\n", readUsername, username);

	return 0;
}
