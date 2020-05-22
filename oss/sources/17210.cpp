#include <iostream>

int main()
{
	int doorCount;
	std::cin >> doorCount;

	int firstDoorOpenWay;
	std::cin >> firstDoorOpenWay;

	if (doorCount > 5)
	{
		std::cout << "Love is open door" << std::endl;
		return 0;
	}

	int doorOpenWay = firstDoorOpenWay;
	for (int i = 0; i < doorCount - 1; i++)
	{
		doorOpenWay = doorOpenWay == 0 ? 1 : 0;

		std::cout << doorOpenWay << std::endl;
	}

	return 0;
}

