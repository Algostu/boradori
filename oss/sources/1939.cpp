#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, H;
    std::cin >> N >> H;

    std::vector<long long> stalagmites(N);
    stalagmites.clear();

    std::vector<long long> stalactites(N);
    stalactites.clear();

    for (int i = 0; i < N; i++)
    {
        long long wall;
        std::cin >> wall;
        if (i % 2 == 0)
            stalagmites.push_back(wall);
        else
            stalactites.push_back(wall);
    }

    std::sort(stalagmites.begin(), stalagmites.end());
    std::sort(stalactites.begin(), stalactites.end());

    int brickWallCount = N;
    int brickWall = N;

    for (int i = 1; i <= H; i++)
    {
        long long answer = std::lower_bound(stalagmites.begin(), stalagmites.end(), i) - stalagmites.begin();
        answer += std::upper_bound(stalactites.begin(), stalactites.end(), H - i) - stalactites.begin();
        answer = N - answer;

        if (answer < brickWall)
        {
            brickWall = answer;
            brickWallCount = 1;
        }
        else if (answer == brickWall)
        {
            brickWallCount++;
        }
    }

    std::cout << brickWall << " " << brickWallCount << std::endl;

    return 0;
}