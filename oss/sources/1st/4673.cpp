#include <iostream>
#include <string.h>

int main()
{
	int length = 10000;
	bool selfNumber[length];
	memset(selfNumber, false, sizeof(selfNumber));

	int number = 1;

	while (number < length)
	{
		int sum = number;
		int temp = number;
		while (temp != 0)
		{
			sum += temp % 10;
			temp = temp / 10;
		}

		if (sum <= length)
		{
			selfNumber[sum] = true;
		}
		number++;

	}
	
	for (int i = 1; i < length; i++)
	{
		if (selfNumber[i] == false)
			std::cout << i << std::endl;
	}
}
