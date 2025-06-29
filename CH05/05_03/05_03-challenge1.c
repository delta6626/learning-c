#include <stdio.h>

void line(void)
{
	for (int i = 0; i < 40; i++)
	{
		putchar('-');
	}
	putchar('\n');
}

int main()
{
	puts("How to Fight Off a Robot Attack");
	line();
	puts("A Survival Guide for the 21st Century");
	line();

	return (0);
}
