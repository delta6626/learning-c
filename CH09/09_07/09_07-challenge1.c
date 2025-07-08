#include <stdio.h>

int main()
{
	const char filename[] = "presidents.dat";
	struct person
	{
		char name[32];
		int inauguration;
		int age;
	} presidents[10] = {
			{"George Washington", 1789, 57},
			{"John Adams", 1797, 62},
			{"Thomas Jefferson", 1801, 58},
			{"James Madison", 1809, 58},
			{"James Monroe", 1817, 59},
			{"John Quincy Adams", 1825, 58},
			{"Andrew Jackson", 1829, 62},
			{"Martin Van Buren", 1837, 55},
			{"William Henry Harrison", 1841, 68},
			{"John Tyler", 1841, 51}};
	int x;
	FILE *fp;

	/* open the file */
	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("Unable to open %s\n", filename);
		return (1);
	}

	for (int i = 0; i < 10; i++)
	{
		fwrite(&presidents[i], sizeof(struct person), 1, fp);
	}

	fclose(fp);

	fp = fopen(filename, "rb");

	/* read records from back to front */

	struct person president;

	for (int i = 9; i >= 0; i--)
	{
		fseek(fp, sizeof(struct person) * i, SEEK_SET);
		fread(&president, sizeof(struct person), 1, fp);
		printf("%s was inaugurated in %d at %d years old.\n", president.name, president.inauguration, president.age);
	}

	/* clean-up */
	fclose(fp);
	return (0);
}
