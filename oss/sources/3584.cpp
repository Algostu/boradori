#include <iostream>
#include <unordered_map>
#include <vector>

int FindDepth(std::unordered_map<int, int> &tree, int &node)
{
    int depth = 0;
    int currentNode = node;
    while (currentNode != 0)
    {
        depth++;
        currentNode = tree[currentNode];
    }

    return depth--;
}

int main()
{
    int testCase;
    std::cin >> testCase;

    for (int t = 0; t < testCase; t++)
    {
        int nodeCount = 0;
        std::cin >> nodeCount;

        std::unordered_map<int, int> tree;
        tree.clear();

        for (int n = 0; n < nodeCount - 1; n++)
        {
            int parent, child;
            std::cin >> parent >> child;

            tree[child] = parent;
        }

        int findLeftNode, findRightNode;
        std::cin >> findLeftNode >> findRightNode;

        int findLeftNodeDepth = FindDepth(tree, findLeftNode);
        int findRightNodeDepth = FindDepth(tree, findRightNode);

        if (findLeftNodeDepth > findRightNodeDepth)
        {
            while (findLeftNodeDepth != findRightNodeDepth)
            {
                findLeftNodeDepth--;
                findLeftNode = tree[findLeftNode];
            }
        }
        else if (findLeftNodeDepth < findRightNodeDepth)
        {
            while (findLeftNodeDepth != findRightNodeDepth)
            {
                findRightNodeDepth--;
                findRightNode = tree[findRightNode];
            }
        }

        while (findLeftNode != findRightNode)
        {
            findLeftNode = tree[findLeftNode];
            findRightNode = tree[findRightNode];
        }

        std::cout << findLeftNode << std::endl;
    }

    return 0;
}