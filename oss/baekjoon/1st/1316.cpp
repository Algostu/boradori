#include <iostream>
#include <map>
#include <string>

int main()
{
	    int repeatCount;
		std::cin >> repeatCount;
			    
		int answer = 0;
				    
		for (int i = 0; i < repeatCount; i++)
		{
			std::string input;
			std::cin >> input;
												        
			std::map<char, bool> character;
														        
			bool flag = true;
			
			for (int j = 0; j < input.size(); j++)
			{
				if (character.find(input[j]) == character.end())
				{
					character[input[j]] = true;
																			
					int k = j;
					while (k < input.size())
					{
						if (input[k] != input[j])
							break;
																																			
						k++;
					}
																				
					int distance = k - j;

					if (distance == 1) continue;
					else j += distance - 1;
				}
				else
				{
					flag = false;
					break;
				}
			}
	
			if (flag == true) answer++;
		}

	std::cout << answer << std::endl;

	return 0;
}

