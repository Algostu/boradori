#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	int count = 0;

	while (n > 0)
	{
		count++;
		n -= count;
	}

	if (count % 2 == 0)
	{
		std::cout << count + n << "/" << 1 + -n << std::endl;
	}
	else
	{
		std::cout << 1 + -n << "/" << count + n << std::endl;
	}

	return 0;
}
