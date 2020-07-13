#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> arr;
vector<pair<int,int>> tmp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
        tmp.push_back({a,1});
        tmp.push_back({b+1,-1});
    }

    sort(tmp.begin(),tmp.end());

    int ck{}, s{}, cnt{};

    for (auto &&i : tmp)
    {
        cnt += i.second;
        if(s < cnt){
            s = cnt;
            ck = i.first;
        }
    }

    cout << s << endl;

    for (int i = 0; i < N; i++)
    {
        if(arr[i].first <= ck && arr[i].second >= ck)
            cout << i+1 << " ";
    }

    return 0;
}