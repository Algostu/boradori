#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

bool visit[MAX]={0,};

void BFS(int N, int K){
    queue<pair<int,int>> q;
    q.push({N,0});
    visit[N] = 1;

    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        if(now == K){
            cout << time-1 << endl;
            break;
        }
        if(now+1 < MAX && !visit[now+1]){
            q.push({now+1,time+1});
            visit[now+1] = 1;
        }
        if(now-1 >=0 && !visit[now-1]){
            q.push({now-1,time+1});
            visit[now-1] = 1;
        }
        if(now*2 < MAX && !visit[now*2]){
            q.push({now*2,time+1});
            visit[now*2] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    BFS(N,K);

    return 0;
}