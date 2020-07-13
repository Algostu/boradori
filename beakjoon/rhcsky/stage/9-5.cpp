#include <iostream>

using namespace std;

int main()
{
    int up,down,tree;
    cin >> up >> down >> tree;
    cout << (tree-down-1) / (up-down) + 1;
    return 0;
}