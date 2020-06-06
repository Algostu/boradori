// not solved
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>

int main()
{
	int n = 0;
	std::cin >> n;

	std::pair<long, long> points[n];

	long long sortestLength = LLONG_MAX;
	long long sortestXDistance = LLONG_MAX;
	long long sortestYDistance = LLONG_MAX;

	for (int i = 0; i < n; i++)
	{
		long x;
		std::cin >> x;

		long y;
		std::cin >> y;

		for (int j = 0; j < i; j++)
		{
			if (i == j) continue;

			long long xLength = 0;
			if (x > points[j].first)
				xLength = x - points[j].first;
			else 
				xLength = points[j].first - x;
			xLength *= xLength;

			long long yLength = 0;
			if (y > points[j].second)
				yLength = y  - points[j].second;
			else
				yLength = points[j].second - y;
			yLength *= yLength;

			if (xLength < sortestXDistance || yLength < sortestYDistance)
			{
				long long length = xLength + yLength;
				if (length < sortestLength)
				{
					sortestLength = length;

					sortestXDistance = xLength;
					sortestYDistance = yLength; 

					if (sortestLength == 0)
					{
						std::cout << sortestLength << std::endl;
						return 0;
					}
				}
			}
		}

		points[i] = std::make_pair(x, y);
	}
	
	std::cout << sortestLength << std::endl;
	return 0;
}
