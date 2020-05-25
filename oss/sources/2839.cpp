#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int a = 0;
	int b = 0;

	while (a < n / 3)
	{
		int leftSugerKg = n - (a * 3);

		if (leftSugerKg % 5 != 0) 
		{
			a++;
			continue;
		}

		else
		{
			b = leftSugerKg / 5;
			std::cout << a + b << std::endl;
			return 0;
		}

		a++;
	}
	
	if (n % 3 == 0)
	{
		std::cout << n / 3 << std::endl;
		return 0;
	}
	std::cout << "-1" << std::endl;

	return 0;
}
