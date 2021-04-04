#include <bits/stdc++.h>

using namespace std;

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for(int i=0; i<n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    

    vector<int> dfs_r(n);
    for(int i=0; i<n; i++){
        cin >> dfs_r[i];
        if (i){
            if(!is_right_order(i)){
                cout << "0" << endl;
                return;
            }
        }
    }

    cout << "1" << endl;
    
    return 0;
}