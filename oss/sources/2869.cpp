#include <iostream>

int main()
{
	long long v;
	long long a, b;

	std::cin >> a >> b >> v;

	v -= b;

	long long answer;
	if (v % (a - b) == 0) answer = v / (a - b);
	else answer = v / (a - b) + 1;

	std::cout << answer << std::endl;
}
