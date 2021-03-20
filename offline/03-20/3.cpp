#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    int M[51][51];
    set<pair<int, int>> com;
    cin >> N;
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<N; j++){
            M[i][j] = tmp[j] == '1' ? 1 : 0;
            if(M[i][j] == 1) com.insert({i, j});
        }
    }

    int level = 1;
    int total = 0;
    vector<int> res;
    while(com.size()!=0){
        res.push_back(com.size());
        total += com.size();
        for(auto it = com.begin(); it!=com.end();){
            int update_flag = true;
            for(int i=0; i<4; i++){
                if(it->first+dx[i] >= N or it->second+dy[i] >= N) update_flag = false;
                if(M[it->first+dx[i]][it->second+dy[i]] != level) update_flag = false;
            }
            if(update_flag){
                M[it->first][it->second] = level + 1;
                ++it;
            } else {
                it = com.erase(it);
            }
        }
        level++;
    }
    cout << "total: " << total << endl;
    for(int i=0; i<res.size(); i++){
        cout << "size[" << (i+1) << "]" << ": " << res[i] << endl;
    }
    return 0;
} 