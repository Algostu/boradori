#include <iostream>

int main()
{
	int x0, y0, x1, y1, x2, y2, x3, y3;
	std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

	if (x0 == x1)
		x3 = x2;
	else if (x0 == x2)
		x3 = x1;
	else 
		x3 = x0;

	if (y0 == y1)
		y3 = y2;
	else if (y0 == y2)
		y3 = y1;
	else 
		y3 = y0;

	std::cout << x3 << " " << y3 << std::endl;

	return 0;
}
