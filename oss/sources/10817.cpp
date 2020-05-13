#include <iostream>

int main()
{
	int middlenumber;
	int wholenumber[3];

	for (int i = 0; i < 3; i++)
	{
		std::cin >> wholenumber[i];
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
				if (((wholenumber[i] <= wholenumber[i+1]) && (wholenumber[i] >= wholenumber[i+2])) || ((wholenumber[i] >= wholenumber[i+1]) && (wholenumber[i] <= wholenumber[i+2])) ) {
				middlenumber = wholenumber[i];
				break;
			}
		}
		else if (i == 1)
		{
			if (((wholenumber[i] <= wholenumber[i+1]) && (wholenumber[i] >= wholenumber[i-1])) || ((wholenumber[i] >= wholenumber[i+1]) && (wholenumber[i] <= wholenumber[i-1])) ) {
				middlenumber = wholenumber[i];
				break;
			}
		}
		else if (i == 2)
		{
			if (((wholenumber[i] <= wholenumber[i-1]) && (wholenumber[i] >= wholenumber[i-2])) || ((wholenumber[i] >= wholenumber[i-1]) && (wholenumber[i] < wholenumber[i-2])) ) {
				middlenumber = wholenumber[i];
				break;
			}
		}
	}

	std::cout << middlenumber << std::endl;

	return 0;
}
