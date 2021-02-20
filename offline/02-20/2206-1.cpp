#include <bits/stdc++.h>

using namespace std;

struct p{
    int x; int y; int b;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ma[1002][1002];
int v[1002][1002][2];
int n, m;

int bfs(){
    queue<p> qu;
    qu.push({1, 1, 1});
    v[1][1][1] = 1;
    while(!qu.empty()){
        auto c = qu.front();
        qu.pop();
        // cout << c.x << " " << c.y << " " << c.b << endl;
        if(c.x == n and c.y == m) return v[c.x][c.y][c.b];
        
        for(int k=0; k<4; k++){
            int x = c.x + dx[k];
            int y = c.y + dy[k];
            if(1<=x and x<=n and 1<=y and y<=m){
                if(c.b and !v[x][y][c.b-1] and ma[x][y]==1){
                    v[x][y][c.b-1] = v[c.x][c.y][c.b] + 1;
                    qu.push({x, y, c.b-1});
                } else if(!v[x][y][c.b] and ma[x][y]==0) {
                    v[x][y][c.b] = v[c.x][c.y][c.b] + 1;
                    qu.push({x, y, c.b});
                }
            }
        }
    }
    
    return -1;
}

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string in_;
        cin >> in_;
        for(int j=1; j<=m; j++){
            ma[i][j] = in_[j-1] == '1' ? 1 : 0;
        }
    }
    
    cout << bfs() << endl;
}