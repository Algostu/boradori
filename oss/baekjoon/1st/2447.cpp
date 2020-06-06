#include <iostream>

void print(int y, int x)
{
	while (y != 0)
	{
		if (y % 3 == 1 && x % 3 == 1)
		{
			std::cout << " ";
			return;
		}
		y /= 3;
		x /= 3;
	}
	std::cout << "*";
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			print(i, j);
		}
		std::cout << std::endl;
	}
	return 0;
}
	
