#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(const std::string& lhs, const std::string& rhs)
{
	if (lhs.size() == rhs.size())
		return lhs < rhs;
	return lhs.size() < rhs.size();
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::string> inputs(n);
	inputs.clear();

	for (int i = 0; i < n; i++)
	{
		std::string inputString;
		std::cin >> inputString;

		inputs.push_back(inputString);
	}

	std::sort(inputs.begin(), inputs.end(), Compare);

	auto end = std::unique(inputs.begin(), inputs.end());

	for (auto iterator = inputs.begin(); iterator != end; iterator++)
	{
		std::cout << *iterator << '\n';
	}

	return 0;
}

