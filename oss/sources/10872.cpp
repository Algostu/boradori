#include <iostream>

int factorial(int n)
{
	if (n == 1)
		return 1;
	else 
		return n * factorial(n - 1);
}

int main()
{
	int n;
	std::cin >> n;

	if (n == 0)
	{
		std::cout << "1" << std::endl;
		return 0;
	}

	int answer = factorial(n);

	std::cout << answer << std::endl;
	
	return 0;
}
		
