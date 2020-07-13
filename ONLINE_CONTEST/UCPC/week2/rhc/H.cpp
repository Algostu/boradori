#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, tmp, ans{};
    cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    vector<pair<ll,ll>> v;
    ll x = sqrt(N);

    for (int i = 1; i < x+2; i++)
    {
        if(N%i == 0) tmp = ll(N/i);
        else tmp = (ll)((N/i)+1);
        // cout << i << " "<< tmp << endl;
        v.push_back({i,tmp});
        v.push_back({tmp,i});
    }
    for (auto &&i : v)
    {
        cout << i.first << i.second << endl;
    }
    
    sort(v.begin(),v.end());
    cout << "--------------------"<< endl;
    for (auto &&i : v)
    {
        cout << i.first << i.second << endl;
    }
    
    for (int i = 0; i < v.size()-1; i++)
    {
        tmp = v[i+1].first-v[i].first; 
        if(tmp==1){
            cout << v[i].first << " " << v[i].second << endl;
            ans += v[i].second;
        }
        else if(tmp > 1){
            cout << v[i].first << " " << v[i].second << "*" << tmp << endl;
            ans += v[i].second*(tmp);
        }
    }
    
    float y = sqrt(N);
    if(y==(int)y) cout << ans << endl;
    else cout << ans+1 << endl;
    return 0;
}