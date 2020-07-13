#include <bits/stdc++.h>
using namespace std;

vector<int> v[500001];
bool check[500001];
int deep[500001];
int ans{}, cnt{};

void DFS(int x){
    check[x] = true;
    if(v[x].size() == 1){
        ans += cnt;
    }
    cnt++;
    deep[x] = cnt;
    for (int i = 0; i < v[x].size(); i++)
    {   
        cnt = deep[x];
        if(check[v[x][i]] == true) continue;
        int next = v[x][i];
        if(check[next]==false) DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,x,y;
    fill(check,check+50000,false);
    cin >> N;
    for (int i = 0; i < N-1; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<N+1; i++){
        sort(v[i].begin(),v[i].end());
    }

    // for (int i = 0; i < N+1; i++)
    // {   
    //     cout << i << ": ";
    //     for (auto &&x : v[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    DFS(1);
    cout << ans;
    // if(ans & 1) cout << "Yes";
    // else cout << "No";

    return 0;
}