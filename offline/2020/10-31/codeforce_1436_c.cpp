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
    int N;
    long long ans = 1;
    int n = 116;
    const int div = 1000000007;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i % div;
    }
    ans = ans * (41 * 40 * 39) % div;
    ans = ans * (81 * 80 * 79) % div;
    cout << ans << endl;
}

int main(void)
{
    freopen("../input.txt", "r", stdin);
    solve();
}
