#include <iostream>

int main() 
{
	int max = 0;
	int maxNumberIndex = 0;

	for (int i = 0; i < 9; i++)
	{
		int number;
		std::cin >> number;

		if (number > max)
		{
			max = number;
			maxNumberIndex = i + 1;
		}
	}
	std::cout << max << std::endl << maxNumberIndex << std::endl;
}

