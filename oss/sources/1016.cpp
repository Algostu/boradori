#include <iostream>
#include <cmath>

int main()
{
	unsigned long long min, max;
	std::cin >> min >> max;

	unsigned long long squareNumberCount = max - min + 1;
	bool isSquareNumber[max - min + 1] = {false, };

	for (unsigned long long i = 2; i * i <= max; i++)
	{
		unsigned long long m = min / (i * i);
		if (mim % (i * i)) m++;

		while(m * (i * i) <= max)
		{
			isSquareNumber[m * (i * i) - min] = true;

			m++;
		}
	}

	for (int i = 1; i <= max - min; i++)
	{
		if (isSquareNumber[i] == true) squareNumberCount--;
	}

	std::cout << squareNumberCount << std::endl;

	return 0;
}
