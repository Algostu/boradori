#include <iostream>
#include <string>

int main()
{
	int N, M, K, Q;
	std::cin >> N >> M >> K >> Q;

	char rooms[N + 1][M + 1] = { '0', };

	for (int i = 0; i < K; i++)
	{
		int x, y;
		std::cin >> y >> x;

		char c;
		std::cin >> c;

		rooms[y][x] = c;
	}

	for (int i = 0; i < Q; i++)
	{
		std::string windowNumber;
		std::cin >> windowNumber;

		int pointY = 0;
		int pointX = 0;
		
		std::pair<int, int> direction = {0, 0};

		switch (windowNumber[0])
		{
			case 'U':
				{
					pointY = 1;
					pointX = windowNumber[1] - '0';

					direction = { -1, 0 }; 
				}
				break;
			case 'D':
				{
					pointY = N;
					pointX = windowNumber[1] - '0';

					direction = { 1, 0 };
				}
				break;
			case 'L':
				{
					pointX = 1;
					pointY = N - windowNumber[1] - '0';

					direction = { 0, 1 };
				}
				break;
			case 'R':
				{
					pointX = M;
					pointY = N - windowNumber[1] - '0';

					direction = { 0, -1 };
				}
				break;
		}

		int ghostCount = 0;
		int length = 1;
		int ghostLengthSum = 0;

		while (pointX > 0 && pointY > 0 && pointX < M + 1 && pointY < N + 1)
		{
			if (rooms[pointY][pointX] == '!')
			{
				ghostCount++;
				ghostLengthSum += length;
				length++;

				pointX += direction.first;
				pointY += direction.second;
			}
			else if (rooms[pointY][pointX] == '/')
			{
				if (direction.first == 1)
					direction = { 0, 1 };
				else
					direction = { 0, -1 };

				pointX += direction.first;
				pointY += direction.second;
			}
			else if (rooms[pointY][pointX] == '\\')
			{
				if (direction.first == 1)
					direction = { 0, 

				pointX += direction.first;
				pointY += direction.second;
			}
			else 
			{
				pointX += direction.first;
				pointY += direction.second;
			}
		}

		std::cout << ghostCount << " " << ghostLengthSum << std::endl;
	}

	return 0;
}
