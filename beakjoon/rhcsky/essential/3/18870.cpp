#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, x;
    int change{};
    vector<pair<int,int>> v;
    vector<int> ans;
    cin >> N;
    ans.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back({x,i});
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < N; i++)
    {
        ans[v[i].second] = change;
        while(i<N && v[i].first == v[i+1].first){
            i++;
            ans[v[i].second] = change;
        }
        change++;
    }

    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    
    return 0;
}