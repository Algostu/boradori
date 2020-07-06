#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int studentNumber = 0;
    scanf("%d", &studentNumber);

    int groupCount = 0;
    scanf("%d", &groupCount);

    std::vector<int> heights(studentNumber);
    heights.clear();

    for (int i = 0; i < studentNumber; i++)
    {
        int height = 0;
        scanf("%d", &height);

        heights.push_back(height);
    }

    std::vector<int> differenceHeight(studentNumber - 1);
    differenceHeight.clear();

    for (int i = 0; i < heights.size() - 1; i++)
    {
        differenceHeight.push_back(heights[i + 1] - heights[i]);
    }

    std::sort(differenceHeight.rbegin(), differenceHeight.rend());

    int diff = heights[studentNumber - 1] - heights[0];
    int takeCount = groupCount - 1;

    for (int i = 0; i < takeCount; i++)
    {
        diff -= differenceHeight[i];
    }

    std::cout << diff << std::endl;

    return 0;
}