#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    string s;
    cin >> N >> M;

    vector<string> v,ans;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    while (M--)
    {
        cin >> s;
        if(binary_search(v.begin(),v.end(),s)){
            ans.push_back(s);
        }
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}