#include <iostream>

int main()
{
	int numberLength;
	std::cin >> numberLength;

	char number[numberLength];
	std::cin >> number;

	int sum = 0;

	for (int i = 0; i < numberLength; i++)
	{
		sum += number[i] - '0';
	}

	std::cout << sum << std::endl;
}

