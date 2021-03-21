#include <bits/stdc++.h>

using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        int ans = 0;
        int R, C;
        cin >> R >> C;
        int m[R+2][C+2];
        memset(m, 0, sizeof m);
        set<pair<int, int>> can;
        for(int r=1; r<=R; r++)
            for(int c=1; c<=C; c++){
                cin >> m[r][c];
                can.insert({r, c});
            }         
        while(!can.empty()){
            for(auto it=can.begin(); it!=can.end(); ){
                int max_val = 0;
                int c_r = it->first, c_c = it->second;
                // cout << c_r << " " << c_c << " " << m[c_r][c_c] << endl;
                for(int i=0; i<4; i++){
                    // cout << m[c_r+dr[i]][c_c+dc[i]] << endl;
                    max_val = max(max_val, m[c_r+dr[i]][c_c+dc[i]]);
                }
                // cout << "max value: " << max_val << endl;
                if(m[c_r][c_c] + 1 < max_val){
                    ans += (max_val - 1 - m[c_r][c_c]);
                    m[c_r][c_c] = max_val - 1;
                    for(int i=0; i<4; i++){
                        if (c_r + dr[i] > 0 and c_r + dr[i] <= R and c_c + dc[i] > 0 and c_c + dc[i] <= C)
                        if (m[c_r+dr[i]][c_c+dc[i]] + 1 < max_val - 1){
                            can.insert({c_r+dr[i], c_c+dc[i]});
                        }
                    }
                }
                it = can.erase(it);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}