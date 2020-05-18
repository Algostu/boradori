#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float up,down,tree;
    cin >> up >> down >> tree;
    cout << (tree-up)/(up-down) << endl;
    cout << ceil((tree-up)/(up-down)) +1;
    return 0;
}
