#include <stdio.h>

void add(int a, int b)
{
	int r = a + b;
	printf("Result of addition is %d\n", r);
}

void subtract(int a, int b)
{
	int r = a - b;
	printf("Result of subtraction is %d\n", r);
}

void multiply(int a, int b)
{
	int r = a * b;
	printf("Result of multiplication is %d\n", r);
}

float divide(int a, int b)
{
	float r = a / b;
	return r;
}

int main()
{
	int a, b;

	printf("Enter two values, separated by a space: ");
	scanf("%d", &a);
	scanf("%d", &b);

	add(a, b);
	subtract(a, b);
	multiply(a, b);
	printf("%d / %d = %f\n", a, b, divide(a, b));

	return 0;
}
