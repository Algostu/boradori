#include <iostream>
#include <string>

int main()
{
int point[26];
	std::fill_n(point, 26, -1);

	std::string word;
	std::cin >> word;

	for (int j = 0; j < word.size(); j++)
	{
		if (point[word[j] - 'a'] == -1) point[word[j] - 'a'] = j;
	}

	for (int j = 0; j < 26; j++)
	{
		std::cout << point[j] << " ";
	}
	std::cout << std::endl;
}

	
	
