#include <iostream>
#include <string>

int main()
{
	std::string input;

	std::getline (std::cin, input);

	bool flag = false;

	int wordCount = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ') flag = false;
		else if (input[i] != ' ' && flag == false)
		{
			wordCount++;
			flag = true;
		}
	}

	std::cout << wordCount << std::endl;


	return 0;
}
