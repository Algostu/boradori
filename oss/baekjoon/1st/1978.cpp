#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int answer = 0;
	while (n > 1)
	{
		bool isPremier = true;

		int t;
		std::cin >> t;
		if (t == 1) continue;

		for (int i = 2; i < t; i++)
		{
			if (t % i == 0)
			{
				isPremier = false;
				break;
			}
		}

		if (isPremier == true) 
		{
			answer++;
		}

		n--;
	}

	//std::cout << "answer : ";
	std::cout << answer << std::endl;

	return 0;
}
