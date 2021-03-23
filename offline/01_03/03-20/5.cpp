#include <bits/stdc++.h>

using namespace std;
int dx[3] = {-1, 0, 1};
int dy[3] = {0, 1, 0};
int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int result = 987654321;
    int N, M;
    cin >> N >> M;
    int m[21][1001] = {0};
    vector<int> starts;

    for(int i=0; i<M; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<N; j++){
            if(tmp[j] == 'c') { starts.push_back(j); m[i][j] = 1; }
            else if (tmp[j] == '.') m[i][j] = 1;
            else m[i][j] = 0;
        }
    }

    for(int idx=0; idx<starts.size(); idx++){
        int c_r = 0, c_c = starts[idx];
        int spl = 0;
        int visited[21][1001];
        memset(visited, 0, sizeof visited); 
        queue<pair<int, int>> qu;
        visited[c_r][c_c] = 1;
        qu.push({c_r, c_c});
        while(!qu.empty()){
            auto c = qu.front(); qu.pop();
            if(c.first == M-1) { spl = visited[c.first][c.second] -1 ; break; }
            for(int i=0; i<3; i++){
                int next_r = c.first+dy[i];
                int next_c = c.second+dx[i];
                if(next_r >= 0 and next_r < M and next_c >= 0 and next_c < N){
                    if(!visited[next_r][next_c] and m[next_r][next_c]){
                        visited[next_r][next_c] = visited[c.first][c.second] + 1;
                        qu.push({next_r, next_c});
                    }
                }
            }
        }
        // cout << spl << endl;
        if(spl == 0) continue;
        result = min(result, spl);
    }

    if(result == 987654321) cout << "-1" << endl;
    else cout << (result-M+1) << endl;

    return 0;
}