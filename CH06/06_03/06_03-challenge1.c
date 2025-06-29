#include <stdio.h>

int main()
{
	int ages[] = {20, 30, 40, 50, 60};
	for (int i = 0; i < 5; i++)
	{
		printf("I know someone who is %d years old\n", ages[i]);
	}
	return 0;
}
