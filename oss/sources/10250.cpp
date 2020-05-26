#include <iostream>

int main()
{
	long long testCases;
	std::cin >> testCases;

	while (testCases > 0)
	{
		long long h, w, n;
		std::cin >> h >> w >> n;

		std::cout << (n - 1) % h + 1;
		std::cout.width(2);
		std::cout.fill('0');
		std::cout << (n - 1) / h + 1 << std::endl;

		testCases--;
	}

	return 0;
}
