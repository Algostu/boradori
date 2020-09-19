#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	int m;
	std::cin >> m;

	std::vector<unsigned int> card(n);
	card.clear();

	for (int i = 0; i < n; i++)
	{
		unsigned int number;
		std::cin >> number;

		card.push_back(number);
	}

	for (int i = 0; i < m; i++)
	{
		std::sort(card.begin(), card.end());

		unsigned int sumValue = card[0] + card[1];
		card[0] = card[1] = sumValue;
	}

	unsigned long answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += card[i];
	}

	std::cout << answer << std::endl;

	return 0;
}
