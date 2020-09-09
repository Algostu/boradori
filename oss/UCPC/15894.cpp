#include <iostream>

int main()
{
	unsigned long n;
	std::cin >> n;

	if (n == 1)
	{
		std::cout << 4 << std::endl;
		return 0;
	}
	
	unsigned long answer = 1 + n + n + n + (n - 1); 

	std::cout << answer << std::endl;

	return 0;
}             
