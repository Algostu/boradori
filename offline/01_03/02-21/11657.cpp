// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

bool bellman(vector<pair<int, int>> weight[], vector<long long> &dist, int n){
    dist[1] = 0;
    for(int i=0; i<n; i++){
        for(int w=1; w<=n; w++){
            if(dist[w] != INF)
            for(auto &it:weight[w]){
                int v = it.first;
                int cost = it.second;
                if(i==n-1 and dist[v] > dist[w]+cost) return false;
                dist[v] = min(dist[v], dist[w] + cost);
            }
        }
    }  
    return true;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> weight[n+1];
    vector<long long> dist(n+1, INF);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weight[u].push_back({v, w});
        // weight[v].push_back({u, w});
    }

    if(!bellman(weight, dist, n)) cout << "-1\n";
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] >= INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}