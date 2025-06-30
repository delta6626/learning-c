#include <stdio.h>
#include <string.h>

struct Birthday
{
	int day;
	int month;
	int year;
};

struct Person
{
	struct Birthday birthday;
	float height;
	char name[30];
};

int main()
{
	struct Person me;
	me.birthday.day = 13;
	me.birthday.month = 6;
	me.birthday.year = 2004;
	me.height = 0.0017f;
	strcpy(me.name, "Hasan");

	printf("%s was born on %d/%d/%d and is %f kilometers tall\n", me.name, me.birthday.day, me.birthday.month, me.birthday.year, me.height);

	return 0;
}
