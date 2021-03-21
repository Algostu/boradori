#include <bits/stdc++.h>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

struct Lshape{
    int r;
    int c;
    int dr;
    int dc;
};

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        int ans = 0, R, C;
        cin >> R >> C;
        int m[R][C] = {0};
        int s[R][C][4] = {0};
        auto cmp = [](const Lshape & a, const Lshape & b){
            return a.r != b.r ? a.r < b.r : 
            (a.c != b.c ? a.c < b.c : 
            (a.dr != b.dr ? a.dr < b.dr : 
            (a.dc < b.dc)));
        };
        set<Lshape, decltype(cmp)> points(cmp);
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                cin >> m[r][c];
                if(m[r][c] == 1) {
                    for(int i=0; i<4; i++){
                        s[r][c][i] = 1;
                        points.insert({r, c, dr[i], dc[i]});  
                    }
                }      
            }
        }
        int level = 1;
        while(!points.empty()){
            for(auto it=points.begin(); it!=points.end(); ){
                bool update_flag = false;
                int n_r = it->r + level * it->dr, n_c = it->c + level * it->dc;
                if(n_r >= 0 and n_r < R and n_c >= 0 and n_c < C and m[n_r][n_c]){
                    int dir_idx = abs(it->dr)*(1-it->dr) + abs(it->dc)*(2-it->dc);
                    s[it->r][it->c][dir_idx] = level+1;
                    int u, v;
                    u = v = (dir_idx + 1) % 4;
                    do {
                        if(s[it->r][it->c][u] >= (level+1)/2){
                            update_flag=true;
                            if((level+1) >= 4 and (level+1) % 2 == 0){
                                // cout << "row, col = " << it->r << ", " << it->c << endl;
                                // cout << n_r << " " << n_c << endl;
                                ans++;
                            }
                        }
                        u = (u + 2) % 4;
                    } while(u != v);
                } 
                if (update_flag){
                    it++;
                }
                else {
                    it = points.erase(it);
                }
            }
            level++;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}