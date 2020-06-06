#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int n, m, answer = 64;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	a.clear();

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			int c = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int o = 0; o < 8; o++)
				{
					bool b = (k % 2) ^ (o % 2) ^ (a[i + k][j + o] == 'B' ? 1 : 0);
					c += b;
				}
			}

			c = std::min(c, 64 - c);
			answer = std::min(answer, c);
		}
	}

	std::cout << answer << std::endl;
	
	return 0;
}
