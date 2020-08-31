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

#define FIXED_VAL 100000000
#define FIXED_LEN 9

using namespace std;

string numbers[16];
int ans = 0;
int total = 0;
int fixedRem;
string nums[15];
int K, N;

int recursive_modular(string a)
{
    if (a.length() <= FIXED_LEN)
    {
        return stoi(a) % K;
    }
    else
    {
        int len = a.length();
        int upperBitRem = recursive_modular(a.substr(0, len - FIXED_LEN)) % K;
        int curBitRem = stoi(a.substr(len - FIXED_LEN, FIXED_LEN)) % K;
        return ((upperBitRem * fixedRem) % K + curBitRem) % K;
    }
}

void recurse(int mask, int taken, string pref)
{
    if (taken == N)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (((mask >> i) & 1) == 0)
        {
            recurse((mask | (1 << i)), taken + 1, pref + nums[i]);
        }
    }
}

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b, r);
}

void solve(int test_num = 0)
{
    cin >> N;
    vector<int> v(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
        v[i] = i;
    }
    cin >> K;
    fixedRem = FIXED_VAL % K;
    do
    {
        string result = "";
        for (int i = 0; i < N; i++)
        {
            result += nums[v[i]];
        }
        total++;
        if (recursive_modular(result) == 0)
        {
            ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

    if (ans == 0)
    {
        cout << "0/1\n";
    }
    else
    {
        int div = gcd(total, ans);
        ans /= div;
        total /= div;
        cout << ans << "/" << total << "\n";
    }
}

int main(void)
{
    freopen("../input.txt", "r", stdin);
    solve();
}
