// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

struct flight{
    int v;
    int c;
    int d;
    
    bool operator<(const flight & copy) const{
    	return this->d < copy.d;
	}
};



void dijkstra(vector<flight> W[], int n, int limit){
    int memo[101][10001];
    for(int i=0; i<=100; i++)
        for(int j=0; j<=10000; j++)
            memo[i][j] = INF;
	set<flight> heap;
    heap.insert({1, 0, 0});
    memo[1][0] = 0;
    while(!heap.empty()){ 
        auto low = heap.begin(); heap.erase(low);
        int w = low->v;
        int c = low->c;
        int d = low->d;
        if(memo[w][c] < d) continue;

        for(auto &v : W[w]){
            if(c+v.c <= 10000)
            if(memo[w][c] + v.d < memo[v.v][c+v.c]){
                memo[v.v][c+v.c] = memo[w][c] + v.d;
                heap.insert({v.v, c+v.c, memo[v.v][c+v.c]});
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=limit; i++)
    	ans = min(ans, memo[n][i]);
    if(ans >= INF) cout << "Poor KCM\n";
    else cout << ans << "\n";
} 

int main() {
    int T;
    cin >> T;
    for(int j=0; j<T; j++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<flight> W[101];
        for(int i=0; i<k; i++){
            int u, v, c, w;
            cin >> u >> v >> c >> w;
            W[u].push_back({v, c, w});
        }
        dijkstra(W, n, m);
    }
    return 0;
}
