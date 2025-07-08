#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_file(const char *f)
{
	char name[32];
	FILE *fp = fopen(f, "w");
	if (fp == NULL)
	{
		printf("An error occured while opening the file.\n");
		exit(-1);
	}
	else
	{
		printf("Type your name: ");
		scanf("%s", name);
		fputs(name, fp);
		printf("%s has written to the file %s\n", name, f);
		fclose(fp);
	}
}

void read_file(const char *f)
{
	FILE *fp = fopen(f, "r");
	char ch;

	if (fp == NULL)
	{
		printf("An error occured while reading the file.\n");
		exit(-1);
	}

	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		else
		{
			printf("%c", ch);
		}
	}

	printf("\n");

	fclose(fp);
}

void delete_file(const char *f)
{
	int status = unlink(f);
	if (status == 0)
	{
		printf("%s has been deleted successfully\n", f);
	}
	else
	{
		printf("An error occured while deleting the file.\n");
		exit(-1);
	}
}

int main()
{
	const char filename[] = "stuff.dat";

	create_file(filename);
	read_file(filename);
	delete_file(filename);

	return 0;
}
