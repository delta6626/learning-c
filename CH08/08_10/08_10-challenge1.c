#include <stdio.h>
#include <stdlib.h>

struct m
{
	char l;
	int i;
};

int main()
{
	struct m *a[26];
	for (int i = 0; i < 26; i++)
	{
		a[i] = malloc(sizeof(struct m));
		if (a[i] == NULL)
		{
			printf("Error allocating memory!");
			exit(0);
		}
		a[i]->l = 'A' + i;
		a[i]->i = i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("The letter at position %d is %c\n", i, a[i]->l);
	}

	for (int i = 0; i < 26; i++)
	{
		free(a[i]);
	}

	return 0;
}
