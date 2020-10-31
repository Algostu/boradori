// not solved
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::pair<long, long>> points(n);
	points.clear();

	for (int i = 0; i < n; i++)
	{
		long x;
		std::cin >> x;

		long y;
		std::cin >> y;

		points.push_back(std::make_pair(x, y));
	}

	std::sort(points.begin(), points.end());

	return 0;
}
