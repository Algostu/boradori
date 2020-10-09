#include <iostream>
#include <string>

int main()
{
	unsigned int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string word;
		std::cin >> word;

		if (word.size() > 10)
		{
			std::string shortWord;
			shortWord.clear();
			shortWord.push_back(word[0]);
			shortWord.append(std::to_string(word.size() - 2));
			shortWord.push_back(word[word.size() - 1]);
			std::cout << shortWord << std::endl;
		}
		else
		{
			std::cout << word << std::endl;
		}
	}
	return 0;
}
