#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	while (true)
	{
		std::vector<int> edge(3);
		edge.clear();

		int e1, e2, e3;
		std::cin >> e1 >> e2 >> e3;
		if (e1 == 0 && e1 == 0 && e3 == 0) break;

		edge.push_back(e1);
		edge.push_back(e2);
		edge.push_back(e3);

		std::sort(edge.begin(), edge.end());

		if (edge[2] * edge[2] == (edge[1] * edge[1]) + (edge[0] * edge[0]))
		{
			std::cout << "right" << std::endl;
		}
		else
		{
			std::cout << "wrong" << std::endl;
		}
	}

	return 0;
}
