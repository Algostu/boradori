#include <bits/stdc++.h>
using namespace std;

int N, BIT, x;
string q;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while (N--)
    {
        cin >> q;
        if (q == "add")
        {
            cin >> x;
            BIT |= (1<<x);
        }
        else if (q == "remove")
        {
            cin >> x;
            BIT &= ~(1<<x);
        }
        else if (q == "check")
        {
            cin >> x;
            if(BIT & (1<<x)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (q == "toggle")
        {
            cin >> x;
            BIT ^= (1<<x);
        }
        else if (q == "all")
        {
            BIT = (1<<21) - 1;
        }
        else if (q == "empty")
        {
            BIT = 0;
        }
    }
    return 0;
}