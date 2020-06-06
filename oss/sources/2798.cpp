#include <iostream>

int main()
{
	int cardCount = 0;
	int maxNumber = 0;
	std::cin >> cardCount;
	std::cin >> maxNumber;

	int cardNumbers[cardCount];

	for (int i = 0; i < cardCount; i++)
	{
		int cardNumber = 0;
		std::cin >> cardNumber;

		cardNumbers[i] = cardNumber;
	}
	
	int answer = 0;
	int useCardCount = 0;

	for (int i = 0; i < cardCount - 2; i++)
	{
		for (int j = i + 1; j < cardCount - 1; j++)
		{
			for (int k = j + 1; k < cardCount; k++)
			{
				if (cardNumbers[i] + cardNumbers[j] + cardNumbers[k] <= maxNumber && maxNumber - (cardNumbers[i] + cardNumbers[j] + cardNumbers[k]) < maxNumber - answer)
				{
					answer = cardNumbers[i] + cardNumbers[j] + cardNumbers[k];
				}
			}
		}
	}

	std::cout << answer << std::endl;

	return 0;
}
