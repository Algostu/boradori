// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

struct point{
    int h;
    int x;
    int y;
};

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, H;
    cin >> m >> n >> H;
    int ma[102][102][102];
    int v[102][102][102];
    int ans = 1e9;
    queue<point> p;
    int total = 0;
    for(int h=1; h<=H; h++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> ma[h][i][j];
                if(ma[h][i][j] == 1){
                    p.push({h, i, j});
                    v[h][i][j] = 1;
                }
                if(ma[h][i][j] == 0)
                    total += 1;
            }
        }
    }

    int cnt = 0;
    int i=0;
    for(; i<=n*m*H; i++){
        int size = p.size();
        // cout << size << endl;
        if(size == 0){
            break;
        }
        for(int j=0; j<size; j++){
            auto c = p.front();
            // cout << c.h << " " << c.x << " " << c.y << endl; 
            p.pop();
            for(int k=0; k<6; k++){
                int h = c.h + dz[k];
                int x = c.x + dx[k];
                int y = c.y + dy[k];
                if(1<=h and h<=H and 1<=x and x<=n and 1<=y and y<=m)
                if(ma[h][x][y] == 0 and v[h][x][y] == 0){
                    v[h][x][y] = 1;
                    p.push({h, x, y});
                    cnt += 1;
                }
            }
        }
    }
    cout << cnt << endl;
    if(total != cnt){
        i = -1;
    }

    cout << (i-1) << endl;

    return 0;
}