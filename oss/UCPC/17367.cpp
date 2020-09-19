#include <iostream>
#include <algorithm>
#include <cstring>

double e[7][7][7][1001];

double Reward(int a, int b, int c)
{
	if (a == b && b == c)
		return 10000 + a * 1000;
	else if (a == b || b == c || a == c)
			return 1000 + ( a == b ? a : c) * 100;
	else 
	{
		int max = a;
		max = std::max(max, b);
		max = std::max(max, c);

		return max * 100;
	}
}

double ExpectedValue(int a, int b, int c, int n)
{
	double reward = Reward(a, b, c);
	if (n == 0)
		return reward;

	double& expectedValue = e[a][b][c][n];
	if (expectedValue > 0)
		return expectedValue;

	double compare = 0;
	for (int i = 1; i <= 6; i++)
	{
		compare += ExpectedValue(b, c, i, n - 1);
	}
	return expectedValue = std::max(reward, compare / 6);
}

int main()
{
	int n = 0;
	std::cin >> n;

	memset(e, -1, sizeof(e));


	double answer = 0;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <=6; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				answer += ExpectedValue(i, j, k, n - 3);
			}
		}
	}

	std::cout << std::fixed;
	std::cout.precision(8);
	std::cout << answer / (6 * 6 * 6) << std::endl;
	return 0;
}
