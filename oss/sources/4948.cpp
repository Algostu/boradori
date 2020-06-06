#include <iostream>
#include <cmath>

int main()
{
	const int MAX = 246913;
	bool isPrimeNumber[MAX];
	std::fill_n(isPrimeNumber, MAX, true);

	while (true)
	{
		int n = 0;
		std::cin >> n;
		if (n == 0) break;

		if (n == 1)
		{
			std::cout << "1" << std::endl;
			continue;
		}

		for (int i = 2; i <= sqrt(n * 2); i++)
		{
			if (isPrimeNumber[i] == true)
			{
				for (int j = i + i; j <= n * 2; j += i)
				{
					if (isPrimeNumber[j] == true)
					{
						isPrimeNumber[j] = false;
					}
				}
			}
		}

		int answer = 0;
		for (int i = n + 1; i <= n * 2; i++)
		{
			if (isPrimeNumber[i] == true) answer++;
		}

		std::cout << answer << std::endl;
	}
	
	return 0;
}
