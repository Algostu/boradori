#include <iostream>
#include <cmath>

int main()
{
	freopen("../input.txt", "r", stdin);

	int testCase;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		double startPoint;
		double endPoint;

		std::cin >> startPoint;
		std::cin >> endPoint;

		double length = endPoint - startPoint;
		double middleIndex = 0;
		for(;;middleIndex++)
			if (middleIndex * middleIndex > length)
				break;
		std::cout << middleIndex << " " << floor(sqrt(length) + 1) << std::endl;
			
		if (pow(middleIndex - 1, 2) == length)
		{
			std::cout << 2 * middleIndex - 3 << std::endl;
		}
		else if((pow(middleIndex, 2) + pow(middleIndex - 1, 2)) / 2 >= length)
		{
			std::cout << 2 * (middleIndex - 1) << std::endl;
		}
		else
		{
			std::cout << 2 * (middleIndex - 1) + 1 << std::endl;
		}
	}
}


	
