#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, x, ans{};
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.rbegin(),v.rend());
    
    for (int i = 1; i < N+1; i++)
    {
        ans += v[i-1]*i;
    }
    
    cout << ans << endl;
    
    return 0;
}