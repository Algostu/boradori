// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;
#define MAX 1e9

int ma[1002][1002];
int v[1002][1002];
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void bfs(matrix &ss, int i, int j){
    queue<pair<int, int>> qu;
    qu.push({i, j});
    v[i][j] = 1;

    for(int i=1; i<=n*m; i++){
        int size = qu.size();
        // cout << size << endl;
        if(size == 0) break;
        for(int j=0; j<size; j++){
            auto front = qu.front();
            qu.pop();
            ss[front.first][front.second] = i;
            for(int k=0; k<4; k++){
                int x = front.first + dx[k];
                int y = front.second + dy[k];
                
                if(1<=x and x<=n and 1<=y and y<=m)
                if(ma[x][y] == 0 and v[x][y] == 0){
                    // cout << x << " " << y << endl;
                    v[x][y] = 1;
                    qu.push({x, y});
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string in_;
        cin >> in_;
        for(int j=1; j<=m; j++){
            ma[i][j] = in_[j-1] == '1' ? 1:0;
        }
    }
    
    matrix se(1002, vector<int>(1002, MAX));
    matrix es(1002, vector<int>(1002, MAX));

    memset(v, 0, sizeof(v));
    bfs(se, 1, 1);
    memset(v, 0, sizeof(v));
    bfs(es, n, m);

    int ans = MAX;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++)
    //         cout << se[i][j] << " ";

    //     cout << endl;
    // }

    // cout << endl;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++)
    //         cout << es[i][j] << "        ";

    //     cout << endl;
    // }

    ans = min(ans, se[n][m]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(ma[i][j] == 1){
                int from = min({se[i][j-1], se[i][j+1], se[i-1][j], se[i+1][j]});
                int to = min({es[i][j-1], es[i][j+1], es[i-1][j], es[i+1][j]});
                ans = min(ans, from+to+1);
            }
        }
    }

    if(ans >= MAX)
        ans = -1;

    cout << ans << endl;

    return 0;
}