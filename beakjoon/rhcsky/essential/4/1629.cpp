#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;

ll pow(ll x, ll m)
{
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;

    if (m & 1)
        return pow(x, m - 1) * x;
    ll half = pow(x, m / 2);
    half %= c;
    return (half * half) % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    cout << pow(a, b) % c;
    return 0;
}