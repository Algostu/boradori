#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef vector<vector<int>> matrix;

ostream& operator<<(ostream& os, const matrix& m)
{
    int sz = m.size();
    for (size_t i = 0; i < sz; i++)
    {
        int row_sz = m[i].size();
        for (size_t j = 0; j < row_sz; j++)
        {
            os << m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    matrix adjacent_matrix(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adjacent_matrix[u].push_back(v);
        adjacent_matrix[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        sort(all(adjacent_matrix[i]));
    }

    cout << adjacent_matrix << endl;

    int node, prev_node;
    for(int i=0; i<n; i++){
        cin >> node;
        if(i){
            auto search_node = lower_bound(all(adjacent_matrix[prev_node]), node);
            cout << prev_node << " " <<  node << endl;
            cout << *search_node << endl;
            if(search_node == adjacent_matrix[prev_node].end() or *search_node != node){
                cout << 0 << endl;
                return 0;
            }
        }
        prev_node = node;
    }
    cout << 1 << endl;
    return 0;
}