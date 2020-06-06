#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	int rank[n];
	std::fill_n(rank, n, 1);

	std::pair<int, int> person[n];

	for (int i = 0; i < n; i++)
	{
		int weight = 0;
		std::cin >> weight;
		int height = 0;
		std::cin >> height;

		person[i] = std::pair<int, int>(weight, height);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (person[i].first > person[j].first && person[i].second > person[j].second)
			{
				rank[j]++;
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << rank[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}
