// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

#define MAX 20002
#define INF 987654321

vector<pair<int, int>> weight[MAX];
vector<int> dist(MAX, INF);

int start_point;

void dijkstra(){
    set<pair<int, int>> heap;
    heap.insert({0, start_point});
    dist[start_point] = 0;
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
}

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e >> start_point;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weight[u].push_back({v, w});
    }
    dijkstra();
    for(int i=1; i<=v; i++){
        if(dist[i]==INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}