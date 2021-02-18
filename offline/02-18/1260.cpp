#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, e, s;
    cin >> n >> e >> s;
    vector<set<int>> g(n+1, set<int>());
    for(int i=0; i<e; i++){
        int n1, n2;
        cin >> n1 >> n2;
        g[n1].insert(n2);
        g[n2].insert(n1);
    }
    
    vector<int> st;
    queue<int> qu;
    vector<int> vi(n+1, 0), vii(n+1, 0);
    
    st.push_back(s); qu.push(s);
    
    while(!st.empty()){
        int c = st.back();
        st.pop_back();
        if(vi[c] == 1) continue;
        vi[c] = 1;
        cout << c << " ";
        
        for(auto it = g[c].rbegin(); it != g[c].rend(); it++){
            if(vi[*it] == 0)
                st.push_back(*it);
        }
    }
    cout << "\n";
    while(!qu.empty()){
        int c = qu.front();
        qu.pop();
        if(vii[c] == 1) continue;
        vii[c] = 1;
        cout << c << " ";
        
        for(auto it = g[c].begin(); it != g[c].end(); it++){
            if(vii[*it] == 0)
                qu.push(*it);
        }
    }
    cout << "\n";
    return 0;
}