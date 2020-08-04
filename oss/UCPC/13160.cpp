#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int edgeCount = 0;
    std::cin >> edgeCount;

    std::vector<std::pair<int, int>> edges(edgeCount);
    edges.clear();

    for (int i = 0; i < edgeCount; i++)
    {
        int start, end;
        std::cin >> start >> end;

        std::pair<int, int> edge = std::make_pair(start, end);
        edges.push_back(edge);
    }

    std::sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size() - 1; i++)
    {
        for (int j = i + 1; j < edges.size(); j++)
        {
            
        }
    }

    return 0;
}