#include <iostream>
#include <cmath>

void HanoiTower(int n, int from, int pass, int to)
{
	if (n == 1)
		std::cout << from << " " << to << '\n';
	else
	{
		HanoiTower(n - 1, from, to, pass);
		std::cout << from << " " << to << '\n'; 
		HanoiTower(n - 1, pass, from, to);
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << (1 << n) - 1 << '\n'; 
	HanoiTower(n, 1, 2, 3);

	return 0;
}
