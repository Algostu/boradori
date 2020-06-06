#include <iostream>
#include <utility>
#include <algorithm>

bool Compare(const std::pair<int ,int>& lhs, const std::pair<int, int>& rhs)
{
	if (lhs.second == rhs.second)
		return lhs.first < rhs.first;
	return lhs.second < rhs.second;
}

int main()
{
	int n;
	std::cin >> n;

	std::pair<int, int> numbers[n];
	for (int i = 0; i < n; i++)
	{
		int lhs, rhs;
		std::cin >> lhs >> rhs;

		numbers[i] = std::make_pair(lhs, rhs);
	}

	std::sort(numbers, numbers + n, Compare);

	for (int i = 0; i < n; i++)
	{
		std::cout << numbers[i].first << " " << numbers[i].second << '\n';
	}

	return 0;
}
