#include <iostream>

unsigned long numbers[91] = { 0, };

unsigned long Fabonachi(int n)
{
	if (n <= 1)
		return n;
	else if (numbers[n] != 0)
		return numbers[n];
	else	
	{
		numbers[n] = Fabonachi(n - 1) + Fabonachi(n - 2);

		return 	numbers[n];
	}
}

int main()
{
	int n;
	std::cin >> n;

	Fabonachi(n);
	std::cout << numbers[n] << std::endl;

	return 0;
}
