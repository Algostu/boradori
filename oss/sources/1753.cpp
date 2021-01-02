#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int main()
{
    unsigned int v, e, k;
    std::cin >> v >> e >> k;

    std::vector<std::vector<std::pair<unsigned int, unsigned int>>> node(v + 1);

    for (unsigned int i = 0; i < e; i++)
    {
        unsigned int source, destination, weight;
        std::cin >> source >> destination >> weight;

        node[source].push_back(std::make_pair(weight, destination));
    }

    std::priority_queue<std::pair<unsigned int, unsigned int>> pq;
    pq.push(std::make_pair(0, k));

    constexpr unsigned int MAX_WEIGHT = std::numeric_limits<unsigned int>::max();
    std::vector<unsigned int> weights(v + 1, MAX_WEIGHT);
    weights[k] = 0;

    while (pq.empty() == false)
    {
        const auto &source = pq.top();
        const unsigned int source_distination = -source.first;
        const unsigned int source_index = source.second;

        pq.pop();

        if (source_distination > weights[source_index])
            continue;

        for (const auto &points : node[source_index])
        {
            const unsigned int &nextPointDestination = points.first;
            const unsigned int &nextPointIndex = points.second;

            if (nextPointDestination + source_distination < weights[nextPointIndex])
            {
                weights[nextPointIndex] = nextPointDestination + source_distination;
                pq.push(std::make_pair(-weights[nextPointIndex], nextPointIndex));
            }
        }
    }

    for (unsigned int i = 1; i < v + 1; i++)
    {
        if (weights[i] == MAX_WEIGHT)
        {
            std::cout << "INF" << '\n';
        }
        else
        {
            std::cout << weights[i] << '\n';
        }
    }

    return 0;
}