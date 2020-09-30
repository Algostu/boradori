#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solve(int test_num = 0)
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", (int)ceil((double)abs(a - b) / 10));
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }
}
