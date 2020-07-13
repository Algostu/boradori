#include <bits/stdc++.h>
using namespace std;

vector<pair<string,int>> v;
vector<string> vv;
int N, Q, l, r, m;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        vv.push_back(s);
        v.push_back({s,i});
    }

    sort(v.begin(),v.end());

    while (Q--)
    {
        cin >> s;
        
        if(s[0]>='0' && s[0] <='9'){
            cout << vv[stoi(s)-1] << '\n';
        }
        else{
            l=0; r=N-1;
            while(l <= r){
                m = (l+r)/2;
                if(v[m].first==s){
                    cout << v[m].second+1 << '\n';
                    break;
                }
                else if(v[m].first < s){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
    }
    return 0;
}