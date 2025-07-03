#include <stdio.h>
#include <string.h>

int main()
{
	char title[] = "Pointers don't intimidate me!\n";
	char *pt = title;
	for (int x = 0; x < strlen(title); x++)
	{
		printf("Character at address %p is %c\n", pt + x, *(pt + x));
	}

	return 0;
}
