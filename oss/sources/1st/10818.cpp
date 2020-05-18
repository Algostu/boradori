#include <iostream>

int main()
{
	int arraySize;
	std::cin >> arraySize;

	long min = 1000000;
	long max = -1000000;
	
	for (int i = 0; i < arraySize; i++)
	{
		int number;
		std::cin >> number;

		if (number < min) min = number;
		if (number > max) max = number;
	}

	std::cout << min << " " << max << std::endl;
}
