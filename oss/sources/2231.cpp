#include <iostream>
#include <cmath>

int main()
{
	int n = 0;
	std::cin >> n;

	int answer = 0;

	for (int i = 0; i < n - 2; i++)
	{
		int sum = 0;
		for (int j = 5; j >= 0; j--)
		{
			sum += (i / (int)pow(10, j) % 10);
		}

		sum += i;

		if (sum == n)
		{
			answer = i;
			break;
		}
	}

	std::cout << answer << std::endl;

	return 0;
}
