#include <iostream>

int main()
{
	int totalScore = 0;
	for (int i = 0; i < 5; i++)
	{
		int score = 0;		
		std::cin >> score;

		if (score < 40)
			score = 40;

		totalScore += score;
	}

	std::cout << totalScore / 5 << std::endl;
}
