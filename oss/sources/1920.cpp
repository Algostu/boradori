#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<long> numbers(n);
	numbers.clear();

	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;

		numbers.push_back(number);
	}

	std::sort(numbers.begin(), numbers.end());

	long findingNumberCount;
	std::cin >> findingNumberCount;
	
	while (findingNumberCount > 0)
	{
		int findNumber;
		scanf("%d", &findNumber);
		bool bFind = false;
		
		long left = 0;
		long right = numbers.size() - 1;
		
		while (left <= right)
		{
			int middle = (left + right) / 2;

			if (numbers[middle] == findNumber)
			{
				std::cout << "1" << '\n';
				bFind = true;
				break;
			}
			else if (numbers[middle] > findNumber)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}

		if (bFind == false) std::cout << "0" << '\n';

		findingNumberCount--;
	}

	return 0;
}
