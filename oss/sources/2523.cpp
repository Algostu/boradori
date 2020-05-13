#include <iostream>

int main() {
	int maxStar;
	std::cin >> maxStar;

	for (int i = 1; i <= maxStar; i++)
	{
		int count = i;
		do {
			std::cout << "*";
			count--;
		} while(count > 0);
		std::cout << std::endl;
	}

	for (int i = maxStar -1; i > 0; --i)
	{
		int count = i;
		do {
			std::cout << "*";
			count--;
		} while(count > 0);
		std::cout << std::endl;
	}
}
