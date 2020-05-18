#include <iostream>

int main() {
	int inputNumber;
	std::cin >> inputNumber;
			    
	char answer[inputNumber];
				    
	bool star = true;
	for (int i = 0; i < inputNumber; i++)
	{
		if (star) answer[i] = '*';
		else answer[i] = ' ';
												
		star = !star;
	}
						
	for (int i = inputNumber; i > 0; i--) {
		int k = 2;
											
		while (k > 0)
		{
			for (int j = 0; j < inputNumber; j++)
			{ 
				std::cout << answer[j];
				if (answer[j] == '*') answer[j] = ' ';
				else answer[j] = '*';
																			
			}
			std::cout << std::endl;
			k--;
		}
	}
	
	return 0;
}

