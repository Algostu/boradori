// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

#define MAX 2002
#define INF 987654321

vector<int> dijkstra(vector<pair<int, int>> weight[], int start){
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
    return dist;
}

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        vector<pair<int, int>> weight[MAX];
        int v, e, t;
        int s, g, h;
        cin >> v >> e >> t;
        cin >> s >> g >> h;
        int bridge = 0;
        for(int j=0; j<e; j++){
            int u, v, w;
            cin >> u >> v >> w;
            weight[u].push_back({v, w});
            weight[v].push_back({u, w});
            if((u==g and v==h) or (u==h and v==g))
                bridge = w;
        }
        vector<int> org = dijkstra(weight, s);
        vector<int> ch1 = dijkstra(weight, g);
        vector<int> ch2 = dijkstra(weight, h);
        vector<int> ans;
        for(int j=0; j<t; j++){
            int candidate;
            cin >> candidate;
            int ans1 = org[candidate];
            int ans2 = min(org[g] + ch2[candidate], org[h] + ch1[candidate]);
            if(ans1 == ans2 + bridge) ans.push_back(candidate);
        }
        sort(ans.begin(), ans.end());
        int size = ans.size();
        for(int j=0; j<size; j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}