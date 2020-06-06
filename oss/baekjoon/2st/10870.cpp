#include <iostream>

int Fabonachi(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return Fabonachi(n - 1) + Fabonachi(n - 2);
}

int main()
{
	int n;
	std::cin >> n;

	int answer = Fabonachi(n);

	std::cout << answer << std::endl;
}
