#include <stdio.h>
#include <stdlib.h>

// write the get_input() function here

char *get_input(size_t size)
{
	char *input = malloc(size);
	if (input == NULL)
	{
		printf("Failed to reserve memory");
		free(input);
		exit(1);
	}
	fgets(input, size, stdin);
	for (int x = 0; x < size; x++)
	{
		if (*(input + x) == '\n')
		{
			*(input + x) = '\0';
			break;
		}
	}
	return input;
}

int main()
{
	char *your_name, *your_city;

	printf("Your name: ");
	your_name = get_input(32);
	printf("Your city: ");
	your_city = get_input(32);

	printf("%s lives in %s.\n", your_name, your_city);
	free(your_name);
	free(your_city);

	return 0;
}
