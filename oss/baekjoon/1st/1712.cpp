#include <iostream>

int main()
{
	long long a;
	long long b; 
	long long c;

	std::cin >> a >> b >> c;

	if (b >= c)
	{
		std::cout << "-1" << std::endl;
		return 0;
	}

	long long totalCost = a;
	long long laptopCost = 0;

	int answer = a / (c - b) + 1;	

	std::cout << answer << std::endl;

	return 0;
}
