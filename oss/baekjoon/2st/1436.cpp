#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	int answer = 666; 
	int badNumberIndex = 0;
	while (true)
	{
		int temp = answer;
		bool isBadNumber = false;

		while (true)
		{
			if (temp % 1000 == 666)
			{
				isBadNumber = true;
			}

			temp /= 10;

			if (temp == 0) break;
		}

		if (isBadNumber == true)
		{
			badNumberIndex++;
			if (badNumberIndex == n) break;
		}

		answer++;
	}

	std::cout << answer << std::endl;

	return 0;
}
