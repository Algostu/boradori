#include <bits/stdc++.h>

using namespace std;

#define MAX 20002

int v[MAX];
int n;

void bfs(vector<int> a[]){
    for(int i=1; i<=n; i++){
        if(v[i] != 0) continue;
        v[i] = 1;
        vector<int> st;
        st.push_back(i);
        while(!st.empty()){
            auto front = st.back();
            st.pop_back();
            // cout << front << endl;
            int size = a[front].size();
            for(int k=0; k<size; k++){
                if(v[a[front][k]]==v[front]){
                    cout << "NO\n";
                    return;
                } else if(!v[a[front][k]]){
                    v[a[front][k]]=-v[front];
                    st.push_back(a[front][k]);
                }

            }
        }
    }
    cout << "YES\n";
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        memset(v, 0, sizeof(v));
        vector<int> a[MAX];
        int e;
        cin >> n >> e;
        for(int j=0; j<e; j++){
            int start, end;
            cin >> start >> end;
            a[start].push_back(end);
            a[end].push_back(start);
        }
        bfs(a);
    }
    
    return 0;
}

