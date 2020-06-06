#include <iostream>
#include <string>

void printAnswer(int value)
{
	std::string answer = "";

	while (value != 0)
	{
		int units = value % 10;
		value /= 10;

		std::cout << units;
	}

	std::cout << std::endl;
}

int main()
{
	int lhs = 0;
	int rhs = 0;

	std::cin >> lhs >> rhs;

	int tempLhs = lhs;
	int tempRhs = rhs;

	for (int i = 0; i < 3; i++)
	{
		int lUnits = tempLhs % 10;
		tempLhs /= 10;

		int rUnits = tempRhs % 10;
		tempRhs /= 10;

		if (lUnits > rUnits)
		{
			printAnswer(lhs);
			return 0;
		}
		else if (lUnits < rUnits) 
		{
			printAnswer(rhs);
			return 0;
		}
	}

	return 0;
}
