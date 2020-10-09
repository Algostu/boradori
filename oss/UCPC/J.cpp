#include <iostream>
#include <vector>
#include <numeric>

// 7 3
// 3 1 2 3
// 3 3 4 5
// 3 5 6 7
// 0 0 1 1 1 1 1
// 1 0 1 0 1 0 1
int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> visit(N + 1, 0);

    std::vector<std::vector<int>> moims(M);
    moims.clear();

    int finalResult[N + 1];

    int answer[N + 1];

    for (int i = 0; i < M; i++)
    {
        int k = 0;
        std::cin >> k;

        std::vector<int> moim(k);
        moim.clear();

        for (int j = 0; j < k; j++)
        {
            int index = 0;
            std::cin >> index;

            moim.push_back(index);
            visit[index]++;
        }

        moims.push_back(moim);
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> finalResult[i + 1];
    }

    if (std::accumulate(moims[moims.size() - 1].begin(), moims[moims.size() - 1].end(), 0) / moims[moims.size() - 1].size() != 0)
    {
        std::cout << "NO" << std::endl;
    }

    for(int i = 1; i < visit.size(); i++)
    {
        if (visit[i] == 1 && finalResult[i] == 0)
        {
            
        }
    }

    return 0;
}