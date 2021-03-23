#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    matrix m(28, vector<int>(28, 0));
    matrix v(28, vector<int>(28, 0));
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        string in_;
        cin >> in_;
        for(int j=1; j<=n; j++){
            m[i][j] = in_[j-1] == '1' ? 1:0;
        }
        // cout << endl;
    }

    vector<int> ans;
    vector<pair<int, int>> st;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(m[i][j] == 1 and v[i][j]==0){
                // cout << "i: " << i << "j: " << j << endl;
                st.push_back({i, j});
                v[i][j] = 1;
                int cnt = 1;
                while(!st.empty()){
                    auto c = st.back();
                    st.pop_back();
                    for(int k=0; k<4; k++){
                        int x = c.first + dx[k];
                        int y = c.second + dy[k];
                        if(m[x][y]==1 and v[x][y] == 0){
                            v[x][y] = 1;
                            cnt += 1;
                            st.push_back({x, y});
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    
    int count = ans.size();
    sort(ans.begin(), ans.end());
    cout << count << "\n";
    for(int i=0; i<count; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}

