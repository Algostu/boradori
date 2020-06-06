#include <iostream>
#include <cmath>

int main()
{
	int n;
	std::cin >> n;

	while (n > 0)
	{
		int x1, y1, r1, x2, y2, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		int k = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		int sum = pow((r1 + r2), 2);
		int dif = pow((r1 - r2), 2);

		if (k == 0)
		{
			if (dif == 0) std::cout << "-1" << std::endl;
			else std::cout << "0" << std::endl;
		}
		else if (k == sum || k == dif) std::cout << "1" << std::endl;
		else if (dif < k && k < sum) std::cout << "2" << std::endl;
		else std::cout << "0" << std::endl;

		n--;
	}

	return 0;
}
