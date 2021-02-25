#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

struct flight{
    int v;
    int c;
    int d;
    
    bool operator>(const flight & copy) const{
    	return this->c > copy.c;
	}
};

void dijkstra(vector<flight> W[], int n, int limit){
    int memo[101][10001];
    for(int i=0; i<=100; i++)
        for(int j=0; j<=10000; j++)
            memo[i][j] = INF;
	queue<flight> heap;
    heap.push({1, 0, 0});
    memo[1][0] = 0;
    while(!heap.empty()){ 
        auto low = heap.front(); heap.pop();
        int w = low.v;
        int c = low.c;
        int d = low.d;
        if(memo[w][c] < d) continue;
        if(w == n) continue;
        for(auto &v : W[w]){
            if(c+v.c <= limit)
            if(memo[w][c] + v.d < memo[v.v][c+v.c]){
                for(int i = c+v.c; i<=limit; i++)
                    if(memo[v.v][i] > memo[w][c]+v.d) memo[v.v][i] = memo[w][c]+v.d;
                    else break;
                memo[v.v][c+v.c] = memo[w][c] + v.d;
                heap.push({v.v, c+v.c, memo[v.v][c+v.c]});
            }
        }
    }
    if(memo[n][limit]>=INF)
        cout << "Poor KCM\n";
    else
        cout << memo[n][limit] << endl;
    return;
} 


int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
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

