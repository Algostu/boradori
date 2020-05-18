#include <iostream>
#include <string>

int main()
{
	int numbers[10] = { 0 };
	
	int a;
	int b;
	int c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	int result = a * b * c;

	std::string resultString = std::to_string(result);

	for (auto iterator = resultString.cbegin(); iterator != resultString.cend(); iterator++)
	{
		if (*iterator == '0') numbers[0]++;
		else if (*iterator == '1') numbers[1]++;
		else if (*iterator == '2') numbers[2]++;
		else if (*iterator == '3') numbers[3]++;
		else if (*iterator == '4') numbers[4]++;
		else if (*iterator == '5') numbers[5]++;
		else if (*iterator == '6') numbers[6]++;
		else if (*iterator == '7') numbers[7]++;
		else if (*iterator == '8') numbers[8]++;
		else if (*iterator == '9') numbers[9]++;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	return 0;
}


