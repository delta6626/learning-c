#include <stdio.h>

int main()
{
	int a;

	printf("How long is the line? ");
	scanf("%d", &a);

	/* write the loop here */

	// With for loop
	for (int i = 0; i < a; i++)
	{
		putchar('-');
	}

	printf("\n");

	// With while loop
	while (a != 0)
	{
		putchar('-');
		a -= 1;
	}

	return (0);
}
