#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);

	int n = 0;
	std::cin >> n;

	int c[10001] = {0};

	for (int i = 0; i < n; i++)
	{
		int temp;
		std::cin >> temp;
		c[temp]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < c[i]; j++)
		{
			std::cout << i << '\n';
		}
	}

	return 0;
}
