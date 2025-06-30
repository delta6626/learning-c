#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

struct person fill(void);
void output(struct person y);

struct person
{
	char name[SIZE];
	int id;
};

/* main program */
int main()
{
	struct person you;

	/* fill the structure */
	you = fill();

	/* output the structure */
	output(you);

	return 0;
}

struct person fill(void)
{
	struct person p;
	printf("Enter your name: ");
	fgets(p.name, SIZE, stdin);
	printf("Enter your ID: ");
	scanf("%d", &p.id);

	return p;
}

void output(struct person y)
{
	printf("ID %d belongs to person %s\n", y.id, y.name);
}
