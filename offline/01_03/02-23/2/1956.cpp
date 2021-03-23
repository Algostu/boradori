#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
typedef vector<vector<int>> matrix;
int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int E, V, val = INF, u, v, d;
    cin >> E >> V;
    matrix dist(E+1, vector<int>(E+1, INF));
    for(int i=0; i<V; i++){
        cin >> u >> v >> d;
        dist[u][v] = d;
    }
    for(int w=1; w<=E; w++) for(int u=1; u<=E; u++) for(int v=1; v<=E; v++) dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
    for(int i=1; i<=E; i++) val = min(val, dist[i][i]); 
    cout << (val == INF ? -1 : val) << endl;
    return 0;
}
