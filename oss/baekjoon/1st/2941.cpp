#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;

	int answer = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'c')
		{
			if (input[i + 1] == '=' || input[i + 1] == '-') i++;
		}

		if (input[i] == 'l' || input[i] == 'n')
		{
			if (input[i + 1] == 'j') i++;
		}

		if (input[i] == 'd')
		{
			if (input[i + 1] == '-') i++;
			else if(i < input.size() - 2 && input[i + 1] == 'z' && input[i + 2] == '=') i += 2;
		}
		
		if (input[i] == 's' || input[i] == 'z')
		{
			if (input[i + 1] == '=') i++;
		}

		answer++;
	}

	std::cout << answer << std::endl;

	return 0;
}

