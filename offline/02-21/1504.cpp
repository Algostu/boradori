// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

#define MAX 802
#define INF 987654321

vector<pair<int, int>> weight[MAX];

int dijkstra(int start, int end){
    vector<int> dist(MAX, INF);
    set<pair<int, int>> heap;
    heap.insert({0, start});
    dist[start] = 0;
    while(!heap.empty()){
        auto top = heap.begin();
        int c = top->first;
        int p = top->second;
        heap.erase(top);

        if(dist[p] < c) continue;
        // cout << p << " " << c << endl;
        for(auto it=weight[p].begin(); it!=weight[p].end(); it++){
            int current = dist[it->first];
            int update = dist[p] + it->second;
            // cout << update << " " << current << endl;
            if(current > update){
                dist[it->first] = update;
                heap.insert({update, it->first});
            }
        }
    }
    return dist[end];
}

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weight[u].push_back({v, w});
        weight[v].push_back({u, w});
    }
    int m1, m2;
    cin >> m1 >> m2;
    long long a = (long long)dijkstra(1, m1) + dijkstra(m1, m2) + dijkstra(m2, v);
    long long b = (long long)dijkstra(1, m2) + dijkstra(m2, m1) + dijkstra(m1, v);
    long long ans = min(a, b);
    if(ans >= INF) cout << -1 << endl;
    else cout << ans;
    
    return 0;
}