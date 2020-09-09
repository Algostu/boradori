#include <iostream>
#include <string>

int main()
{

	std::string fullSentence;
	std::getline(std::cin, fullSentence);

	unsigned int answer = 0;

	for (int i = 0; i < fullSentence.size(); i++)
	{
		if (answer == 0 && fullSentence[i] == 'U') answer++;
		else if (answer == 1 && fullSentence[i] == 'C') answer++;
		else if (answer == 2 && fullSentence[i] == 'P') answer++;
		else if (answer == 3 && fullSentence[i] == 'C') answer++;
	}

	if (answer == 4)
	{
		std::cout << "I love UCPC" << std::endl;
	}
	else {
		std::cout << "I hate UCPC" << std::endl;
	}

	return 0;
}
