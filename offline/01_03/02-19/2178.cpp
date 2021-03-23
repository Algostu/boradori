// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ma[102][102];
int v[102][102];
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        string in_;
        cin >> in_;
        for(int j=1; j<=m; j++){
            ma[i][j] = in_[j-1] == '1' ? 1 : 0;
        }
    }

    int ans = 0;
    queue<pair<int, int>> p;
    p.push({1, 1});
    v[1][1] = 1;
    for(int i=1; i<=n*m; i++){
        int size = p.size();
        // cout << size << endl;
        for(int j=0; j<size; j++){
            auto c = p.front();
            // cout << c.first << " " << c.second << endl; 
            p.pop();
            for(int k=0; k<4; k++){
                int x = c.first + dx[k];
                int y = c.second + dy[k];
                if(ma[x][y] == 1 and v[x][y] == 0){
                    if(x==n and y==m){
                        cout << i+1 << endl;
                        return 0;
                    }
                    v[x][y] = 1;
                    p.push({x, y});
                }
            }
        }
    }

    return 0;
}