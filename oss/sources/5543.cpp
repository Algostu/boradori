#include <iostream>

int main()
{
	int chipestBugerCost = 3000;
	int chipestDrinkCost = 3000;
	
	for (int i = 0; i < 5; i++)
	{
		int price;
		std::cin >> price;

		if (i < 3)
		{
			if (price < chipestBugerCost) 
			{
				chipestBugerCost = price;
			}
		}
		else {
			if (price < chipestDrinkCost)
			{
				chipestDrinkCost = price;
			}
		}
	}

	int totalPrice = chipestBugerCost + chipestDrinkCost - 50;
	std::cout << totalPrice << std::endl;
}
					



