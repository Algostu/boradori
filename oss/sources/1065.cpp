#include <iostream>

int main()
{
	int n; std::cin >> n;

	if (n < 100)
	{
		std::cout << n << std::endl;
		return 0;
	}

	int answer = 99;
	for (int i = 100; i <= n; i++)
	{
		int n1 = i / 100;
		int n2 = (i % 100) / 10;
		int n3 = (i % 100) % 10;

		if ((n1 - n2) == (n2 - n3)) answer++;
	}

	std::cout << answer << std::endl;

	return 0;
}
