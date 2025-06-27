#include <stdio.h>

int main()
{
	int a, b;

	printf("Enter two values, separated by a space: ");
	scanf("%d", &a);
	scanf("%d", &b);

	printf("a + b = %d\n", a + b);
	printf("a-b = %d\n", a - b);
	printf("a x b = %d\n", a * b);
	printf("a / b = %.2f\n", (float)a / b);
	printf("Modulus of a and b = %d\n", a % b);
	printf("a bit shifted to the right by b = %d\n", a >> b);
	printf("a bit shifted to the left by b = %d\n", a << b);

	return 0;
}
