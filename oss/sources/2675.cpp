#include <iostream>
#include <string>

int main()
{
	int testCase;
	std::cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int repeatCount;
		std::cin >> repeatCount;

		std::string input;
		std::cin >> input;

		std::string answer = "";

		for (int j = 0; j < input.size(); j++)
		{
			for (int k = 0; k < repeatCount; k++)
			{
				answer.push_back(input[j]);
			}
		}

		std::cout << answer << std::endl;
	}

}
