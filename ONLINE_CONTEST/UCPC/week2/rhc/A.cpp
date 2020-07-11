#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    long long ans{};
    cin >> N >> M;
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < M; i++)
    {
        sort(v.begin(),v.end());
        int temp = v[0] + v[1];
        v[0] = v[1] = temp;
    }

    for (auto &&i : v)
    {
        ans += i;
    }
    
    cout << ans << endl;
    return 0;
}