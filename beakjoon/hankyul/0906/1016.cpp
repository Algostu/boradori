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

#define MAX_LEN 1000001

using namespace std;

void eratos(long long start, long long n)
{
    if (n <= 1)
        return;

    bool* PrimeArray = new bool[MAX_LEN];

    for (long long i = 2; i * i <= n; i++)
        PrimeArray[i] = true;

    for (long long i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
        {
            for (long long j = i * i; j * j <= n; j += i)
                PrimeArray[j] = false;
        }
    }
    int ans = 0;
    for (size_t i = 0; i * i < n; i++)
    {
        if (PrimeArray[i])
            ans++;
    }

    cout << ans;
}

void solve(int test_num = 0)
{
    long long start, end;
    int limitNum, totalNum, verdictedNum;
    char verdicted[MAX_LEN] = { 0 };
    char eratosNet[MAX_LEN] = { 0 };
    cin >> start >> end;

    totalNum = end - start + 1;
    verdictedNum = 0;

    eratos(0, end);
}

int main(void)
{
    freopen("../input.txt", "r", stdin);
    solve();
}
