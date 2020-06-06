#include <iostream>
#include <cmath>

int main()
{
	double r;
	std::cin >> r;

	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << pow(r, 2) * M_PI << std::endl;
	std::cout << pow(r, 2) * 2 << std::endl;

	return 0;
}
