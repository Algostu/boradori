#include <bits/stdc++.h>
using namespace std;

const pair<int,int> UP = {-1,0};
const pair<int,int> DOWN = {1,0};
const pair<int,int> RIGHT = {0,1};
const pair<int,int> LEFT = {0,-1};

int cnt{}, dist{};
pair<int,int> start;
vector<vector<char>> v;

int N,M,K,Q;
int x,y;
char s;
string ss;

inline int cal_dist(pair<int,int> start, pair<int,int> pos){
    return abs(start.first - pos.first) + abs(start.second - pos.second) + 1;
}

inline void solve(pair<int,int> pos, pair<int,int> dir){
    if(pos.first >= N || pos.second >= M || pos.first < 0 || pos.second < 0){
        printf("%d %d\n",cnt, dist);
        cnt = 0;
        dist = 0;
        return;
    }
    if(v[pos.first][pos.second] == '!'){
        cnt++;
        dist += cal_dist(start,pos);
        solve({pos.first+dir.first,pos.second+dir.second},dir);
    }
    else if(v[pos.first][pos.second]=='/'){
        if(dir == UP) dir = RIGHT;
        else if(dir == DOWN) dir = LEFT;
        else if(dir == LEFT) dir = DOWN;
        else dir = UP;
        solve({pos.first+dir.first,pos.second+dir.second},dir);
    }
    else if(v[pos.first][pos.second] == '\\'){
        if(dir==UP) dir = LEFT;
        else if(dir==DOWN) dir = RIGHT;
        else if(dir == LEFT) dir = UP;
        else dir = DOWN;
        solve({pos.first+dir.first,pos.second+dir.second},dir);
    }
    else{
        solve({pos.first+dir.first,pos.second+dir.second},dir);
    }
}

int main()
{
    scanf("%d %d %d %d", &N,&M,&K,&Q);
    v.reserve(N);
    for (int i = 0; i < N; i++)
    {
        v[i].reserve(M);
    }

    for (int i = 0; i < K; i++)
    {
        cin >> x >> y >> s;
        v[x-1][y-1] = s;
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> ss;
        if(ss[0]=='D'){
            start = {N-1,(ss[1]-'0')-1};
            solve(start,UP);
        }
        else if(ss[0]=='U'){
            start = {0,(ss[1]-'0')-1};
            solve(start,DOWN);
        }
        else if(ss[0]=='R'){
            start = {(ss[1]-'0')-1,M-1};
            solve(start,LEFT);
        }
        else{
            start = {(ss[1]-'0')-1,0};
            solve(start,RIGHT);
        }
    }
    return 0;
}