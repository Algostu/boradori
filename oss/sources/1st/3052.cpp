#include <iostream>
#include <map>

int main()
{
	std::map<int, bool> remainders;
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		int number;
		std::cin >> number;

		number = number % 42;

		if (remainders.find(number) == remainders.end())
		{
			remainders[number] = true;
			count++;
		}
	}

	std::cout << count << std::endl;
}



		
