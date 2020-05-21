#include <iostream>
#include <string>

int main() {
	int repeatCount;
	std::cin >> repeatCount;

	for (int i = 0; i < repeatCount; i++)
	{
		std::string testCase;
		std::cin >> testCase;

		int answer = 0;
		int continuousZeroCount = 0; 

		for (auto iterator = testCase.cbegin(); iterator != testCase.cend(); iterator++)
		{
			if (*iterator == 'O') 
			{
				continuousZeroCount++;
				answer += continuousZeroCount;
			}
			else 
			{
				continuousZeroCount = 0;
			}
		}

		std::cout << answer << std::endl;
	}
}
