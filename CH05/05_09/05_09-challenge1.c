#include <stdio.h>

void line(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		putchar(c);
	}
	putchar('\n');
}

int main()
{
	puts("Report on Extraterrestrial Activity");
	line(35, '-');

	return (0);
}
