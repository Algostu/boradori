#include <iostream>

int main()
{
	unsigned long n;
	std::cin >> n;

	int numbers[1000001];
	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;
	
	for (int i = 3; i <= n; i++)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
		numbers[i] %= 15746;
	}

	std::cout << numbers[n] << std::endl;

	return 0;
}
