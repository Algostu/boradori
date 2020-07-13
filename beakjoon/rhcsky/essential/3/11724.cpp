#include <bits/stdc++.h>
using namespace std;

vector<int> m[1001];
bool visit[1001] = {0,};

void DFS(int x){
    visit[x] = 1;
    for (int i = 0; i < m[x].size(); i++)
    {
        if(!visit[m[x][i]]) DFS(m[x][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,a,b,cnt{};
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for (int i = 1; i < N+1; i++)
    {
        if(!visit[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;    
    return 0;
}