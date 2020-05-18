#include <iostream>

int main() {
	int number;
	std::cin >> number;

	float maxScore = 0;
	float scores[number];

	for (int i = 0; i < number; i++)
	{
		int score;
		std::cin >> score;

		if (score > maxScore) maxScore = (float)score;

		scores[i] = score;
	}

	float totalScore = 0;
	for (int i = 0; i < number; i++)
	{
		scores[i] = scores[i] / maxScore * 100;
		totalScore += scores[i];
	}
	
	std::cout << totalScore / number << std::endl;

}
