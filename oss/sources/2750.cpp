#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> numbers(n);
	numbers.clear();

	for (int i = 0; i < n; i++)
	{
		int temp;
		std::cin >> temp;

		numbers.push_back(temp);
	}

	std::sort(numbers.begin(), numbers.end());

	for (int i = 0; i < n; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	return 0;
}
