#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;

	int count[26];
	std::fill_n(count, 26, 0);

	for (int i = 0; i < input.size(); i++)
	{
		char temp = input[i];
		if (temp > 'Z') temp -= 'a' - 'A';

		count[(int)(temp - 'A')]++;
	}

	int max = 0;
	int index = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < count[i]) {
			max = count[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (i == index) continue;

		if (max == count[i])
		{
			std::cout << "?" << std::endl;
			return 0;
		}
	}

	std::cout << (char)(index + 65) << std::endl;
	return 0;
}

	
