#include <iostream>
#include <cmath>

int main()
{
	bool isPrimeNumber[10000];
	std::fill_n(isPrimeNumber, 10000, true);
	
	for (int i = 2; i < 10000; i++)
	{
		if (isPrimeNumber[i] == false) continue;

		for (int j = i + i; j <= 10000; j += i)
		{
			isPrimeNumber[j] = false;
		}
	}

	int testCases;
	std::cin >> testCases;

	while (testCases > 0)
	{
		int n;
		std::cin >> n;

		for (int i = n / 2; i > 1; i--)
		{
			if (isPrimeNumber[i] == true)
			{
				int lhs = i;
				int rhs = n - lhs;

				if (isPrimeNumber[rhs] == true)
				{
					std::cout << lhs << " " << rhs << std::endl;
					break;
				}
			}
		}

		testCases--;
	}
	
}
