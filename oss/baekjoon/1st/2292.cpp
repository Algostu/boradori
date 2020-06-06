#include <iostream>

int main()
{
	long long n;
	std::cin >> n;

	long long answer = 0;

	for (int i = 2; i <= n; answer++)
	{
		i += 6 * answer;
	}

	if (n == 1) answer = 1;

	std::cout << answer << std::endl;

	return 0;
}
