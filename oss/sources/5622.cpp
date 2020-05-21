#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;

	int duration = 0;

	for (int i = 0; i < input.size(); i++)
	{
		int r = (int)(input[i] - 'A');

		if ( r == 18 || r == 21) r -= 1;

		r /= 3;

		if (r > 7) r = 7;

		duration += r + 3;
	}

	std::cout << duration << std::endl;

	return 0;
}

