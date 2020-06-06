#include <iostream>
#include <cmath>

int main()
{
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;

	x = abs(x);
	y = abs(y);
	w = abs(w);
	h = abs(h);

	int shortestLengthHeight = abs(h - y) < y ? abs(h - y) : y;
	int shortestLengthWidth = abs(w - x) < x ? abs(w - x) : x;

	int answer = shortestLengthWidth < shortestLengthHeight ? shortestLengthWidth : shortestLengthHeight;

	std::cout << answer << std::endl;
	
	return 0;
}
