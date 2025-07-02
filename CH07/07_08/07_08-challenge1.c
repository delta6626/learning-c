#include <stdio.h>

int main()
{

	char itemName[] = "Donuts";
	int quantity = 10;
	int price = 3.5;
	float totalCost = quantity * price;

	printf("You have purchased %d %s at a price of $%d each. The total cost is $%.2f\n.", quantity, itemName, price, totalCost);

	return 0;
}
