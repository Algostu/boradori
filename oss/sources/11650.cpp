#include <iostream>
#include <utility>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::pair<int , int> numbers[n];
	for (int i = 0; i < n; i++)
	{
		int lhs, rhs;
		std::cin >> lhs >> rhs;
		numbers[i] = std::make_pair(lhs, rhs);
	}

	std::sort(numbers, numbers + n);

	for (int i = 0; i < n; i++)
	{
		std::cout << numbers[i].first << " " << numbers[i].second << '\n'; 
	}

	return 0;
}
