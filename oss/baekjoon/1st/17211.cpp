#include <iostream>

int main()
{
	int n;
	std::cin >> n;
		
	int currentEmoji;
	std::cin >> currentEmoji;
		
	double gg, gb, bg, bb;
	std::cin >> gg >> gb >> bg >> bb;
		
	double goodDayPercentage = 0;
	double badDayPercentage = 0;

	if (currentEmoji == 0)
	{
		goodDayPercentage = 1;
		badDayPercentage = 0;
	}
	else
	{
		goodDayPercentage = 0;
		badDayPercentage = 1;
	}        

	for (int i = 0; i < n; i++)
	{
		double tempGoodDayPercentage = goodDayPercentage;
		double tempBadDayPercentage = badDayPercentage;
		goodDayPercentage = tempGoodDayPercentage * gg + tempBadDayPercentage * bg;
		badDayPercentage = tempBadDayPercentage * bb + tempGoodDayPercentage * gb;
	}

	goodDayPercentage = goodDayPercentage * 10000;
	if ((int)goodDayPercentage % 10 < 5) goodDayPercentage /= 10;
	else goodDayPercentage = goodDayPercentage / 10 + 1;

	badDayPercentage = badDayPercentage * 10000;
	if ((int)badDayPercentage % 10 < 5) badDayPercentage /= 10;
	else badDayPercentage = badDayPercentage / 10 + 1;

	std::cout << std::fixed;
	std::cout << (int)goodDayPercentage << std::endl << (int)badDayPercentage << std::endl;
	return 0;
}
