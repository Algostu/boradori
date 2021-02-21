    // Created on 강한결의 iPad.

    #include <bits/stdc++.h>
    using namespace std;

    #define INF 987654321
    typedef vector<vector<int>> matrix;

    int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
        int n, m;
        cin >> n >> m;
        matrix d(n+1, vector<int>(n+1, INF));
        
        for(int i=1; i<=n; i++){
            d[i][i] = 0;
        }
        
        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v], w);
        }

        for(int w=1; w<=n; w++)
            for(int u=1; u<=n; u++)
                for(int v=1; v<=n; v++)
                    d[u][v] = min(d[u][v], d[u][w] + d[w][v]);

        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                if(d[u][v] >= INF) cout << "0 ";
                else cout << d[u][v] << " ";
            }
            cout << "\n";
        }

        return 0;
    }