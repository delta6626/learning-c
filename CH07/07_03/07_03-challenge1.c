#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";

	for (int x = 0; string[x] != '\n'; x++)
	{
		if (isalpha(string[x]) && isupper(string[x]))
		{
			putchar(tolower(string[x]));
		}
		else if (isalpha(string[x]) && islower(string[x]))
		{
			putchar(toupper(string[x]));
		}
		else
		{
			putchar(string[x]);
		}
	}

	putchar('\n');
}
