#include <iostream>
#include <map>

int X[6] = {0,1,1,0,-1,-1};
int Y[6] = {2,1,-1,-2,-1,1};

std::map<std::pair<int,int>,int> visitedPoint;

int moveCount;
int answer = 0;

void Move(std::pair<int,int> currentPoint, int index, int n) {
	if (visitedPoint.count({ currentPoint.first, currentPoint.second }) > 0)
	{
		if(n == moveCount)
			answer++;

		return;
	}

	if (n > moveCount) return;

	visitedPoint[{ currentPoint.first , currentPoint.second }] = n;

	Move({ currentPoint.first + X[(index + 1) % 6], currentPoint.second + Y[(index + 1) % 6] }, (index + 1) % 6, n + 1);
						
	Move({ currentPoint.first + X[(index + 5) % 6], currentPoint.second + Y[(index + 5 ) % 6] }, (index + 5 ) % 6, n + 1);
							
	visitedPoint.erase({ currentPoint.first , currentPoint.second });

	return;
}


int main() 
{
	visitedPoint.clear();

	std::cin >> moveCount;
	
	visitedPoint[{0, 0}] = 0;

	Move({ 0, 2 }, 0, 0);

	std::cout << answer << std::endl;

	return 0;
}
