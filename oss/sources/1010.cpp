#include <iostream>
#include <cstring>

int main()
{
	int testCase = 0;
	std::cin >> testCase;

	unsigned long dp[30 + 1][30 + 1];

	while (testCase > 0)
	{
		int n, m;
		std::cin >> n >> m;

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= m; i++)
		{
			dp[1][i] = i;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= m; j++)
			{
				for (int k = j; k >= i; k--)
				{
					dp[i][j] = dp[i][j] + dp[i - 1][k - 1];
				}
			}
		}

		std::cout << dp[n][m] << std::endl;

		testCase--;
	}
	
	return 0;
}
