#include <iostream>

int p[101] = { 0, };

int EdgeLength(int n)
{
	if (n == 1 || n == 2 || n == 3)
		return 1;
	else if (n == 4 || n == 5)
		return 2;
	else if (p[n] != 0)
		return p[n];

	p[n] = EdgeLength(n - 1) + EdgeLength(n - 5);

	return p[n];
}

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		
		std::cout << EdgeLength(n) << '\n';
	}

	return 0;
}
