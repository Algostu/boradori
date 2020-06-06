#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool Compare(std::pair<int, std::string> lhs, std::pair<int, std::string> rhs)
{
	return lhs.first < rhs.first;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::pair<int, std::string>> customers(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> customers[i].first >> customers[i].second;
	}

	std::stable_sort(customers.begin(), customers.end(), Compare);

	for (int i = 0; i < n; i++)
	{
		std::cout << customers[i].first << " " << customers[i].second << '\n';
	}

	return 0;
}
	
