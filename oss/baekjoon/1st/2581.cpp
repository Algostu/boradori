#include <iostream>

int main()
{
	int m, n;
	std::cin >> m >> n;

	int sum = 0;

	bool isFirstPremie = true;
	int minimumPremieNumber = 0;

	while (m <= n)
	{
		bool isPremie = true;

		if (m == 1) isPremie = false;

		for (int i = 2; i < m; i++)
		{
			if (m % i == 0)
			{
				isPremie = false;
				break;
			}
		}

		if (isPremie == true)
		{
			sum += m;

			if (isFirstPremie == true)
			{
				minimumPremieNumber = m;
				isFirstPremie = false;
			}
		}

		m++;
	}

	if (sum == 0)
	{
		std::cout << "-1" << std::endl;
	}
	else
	{
		std::cout << sum << std::endl << minimumPremieNumber << std::endl;
	}

	return 0;
}
