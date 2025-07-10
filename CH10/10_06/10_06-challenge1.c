#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	// seed the randomizer
	srand((unsigned int)time(NULL));
	// allocate storage
	int grid[5][5];
	// populate the grid with random values, 0 through 99
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			grid[x][y] = rand() % 100;
		}
	}
	// quicksort the grid
	qsort(&grid[0][0], 25, sizeof(int), compare);

	// output the grid
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%10d", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}
