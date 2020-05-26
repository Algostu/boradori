#include <iostream>

int Solution(int a, int b)
{
	if (b == 1)
		return 1;
	
	if (a == 0)
		return b;

	return Solution(a - 1, b) + Solution(a, b - 1);
}

int main()
{
	int testCases;
	std::cin >> testCases;

	while (testCases > 0)
	{
		int k, n;
		std::cin >> k >> n;

		std::cout << Solution(k, n) << std::endl;

		testCases--;
	}

	return 0;
}
