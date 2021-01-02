#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int div = 1000000007;
    int n, x, pos, max, min, left, right, middle;
    freopen("input.txt", "r", stdin);
    long long ans = 1;
    cin >> n >> x >> pos;
    max = n - x, min = x - 1;
    left = 0, right = n;

    while (left < right)
    {
        middle = (left + right) / 2;
        if (middle < pos)
        {
            ans = ans * min % div;
            min--;
            cout << middle << endl;
            left = middle + 1;
        }
        else if (middle > pos)
        {
            ans = ans * max % div;
            max--;
            cout << middle << endl;
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }
    cout << max + min << endl;
    for (int i = 1; i <= max + min; i++)
    {
        ans = ans * i % div;
    }

    cout << ans << endl;
    return 0;
}
