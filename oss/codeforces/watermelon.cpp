#include <iostream>

int main()
{
	unsigned int input;
	std::cin >> input;

	for (int lhs = 2; lhs < input; lhs+=2)
	{
		unsigned int rhs = input - rhs;
		if (lhs % 2 == 0 && rhs % 2 == 0)
		{
			std::cout << "YES" << std::endl;
			return 0;
		}
	}

	std::cout << "NO" << std::endl;
}
