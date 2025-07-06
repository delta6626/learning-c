#include <stdio.h>
#include <string.h>

int main()
{
	const char filename[] = "hello.txt";
	char username[50];
	printf("Enter your name: ");
	fgets(username, 50, stdin);

	FILE *fileWriter = fopen(filename, "w");
	if (fileWriter == NULL)
	{
		printf("Error creating file!");
		exit(1);
	}
	else
	{
		fputs(username, fileWriter);
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

	FILE *fileReader = fopen(filename, "r");
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

	fclose(fileReader);

	printf("The string '%s' was written to the file by %s\n", readUsername, username);

	return 0;
}
