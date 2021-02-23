## KCM Travel (백준 10217번 문제)

이 문제를 해결하는데 총 3일이 소요되었다. 진짜 어려운 문제이다. 지금껏 배웠던 Dijkstra, BellmanFord, Floydwarshall, BFS, DFS 모두 다시 공부하고, C++ STL set, map, priority_queue, queue 에 대해서 다시 한번 생각해보는 계기가 되었다.



## 배운점

1. set의 잘못된 사용 : 무분별하게 set을 사용하는 것은 좋지 않다. 특히 이번 문제 처럼 원소의 개수가 많아질 때 set을 사용한다면 메모리 초과를 맞볼 수 있다. 또한 set의 equal을 결정하는 방법에 대해서 다시 한번 생각해야 한다. 여러개의 원소가 있을 때 하나의 비교값만 제출한다면 그건 잘못된 비교 연산이다. set의 equal은 !comp(a, b) && !comp(a, b) 로 판단한다. 즉, a,b가 서로 같다면 두 개의 비교 연산 모두 false가 나올 테니 같다고 판단하는 것이다. 만약 이 연산의 결과로 하나의 원소만 비교하는 연산을 작성한다면 다른 원소 또한 같다고 판단하는 실수를 저지르는 것 이다.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

struct flight{
    int v;
    int c;
    int d;
    
    bool operator>(const flight & copy) const{
    	return this->d > copy.d;
	}
};

void dijkstra(vector<flight> W[], int n, int limit){
    int memo[101][10001];
    for(int i=0; i<=100; i++)
        for(int j=0; j<=10000; j++)
            memo[i][j] = INF;
	priority_queue<flight, vector<flight>, greater<flight>> heap;
    heap.push({1, 0, 0});
    memo[1][0] = 0;
    while(!heap.empty()){ 
        auto low = heap.top(); 
        int w = low.v;
        int c = low.c;
        int d = low.d;
        heap.pop();
        if(memo[w][c] < d) continue;
        if(w == n){
            cout << d << endl;
            return;
        }

        for(auto &v : W[w]){
            if(c+v.c <= limit)
            if(memo[w][c] + v.d < memo[v.v][c+v.c]){
                memo[v.v][c+v.c] = memo[w][c] + v.d;
                heap.push({v.v, c+v.c, memo[v.v][c+v.c]});
            }
        }
    }
    cout << "Poor KCM\n";
    return;
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


```



2. Distance 순서대로 정렬 : 이 문제는 모든 경우의 수를 다 고려해서 풀어야 하는 문제이다. 따라서 어떤 방식으로 고려해야 하는 경우의 수를 줄일것인지 생각해보면 문제의 시간 복잡도를 줄일 수 있다. 단순하게 생각해서 distance가 낮은 순서대로 path를 찾는다면 다른 정답에 비해 3배나 느린 정답을 도출하게 된다. 그렇다면 어떤 방식으로 정답을 도출해야 할 까? 바로 cost 순서대로 정렬하는 것이다. cost가 낮은 순서대로 정답을 찾고 해당 정답보다 큰 경우의 수를 제거하는 식으로 문제를 풀게되면 distance 보다 훨씬 더 빠르게 답을 구할 수 있다.

```cpp
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
	priority_queue<flight, vector<flight>, greater<flight>> heap;
    heap.push({1, 0, 0});
    memo[1][0] = 0;
    int ans = INF;
    while(!heap.empty()){ 
        auto low = heap.top(); 
        int w = low.v;
        int c = low.c;
        int d = low.d;
        heap.pop();
        if(memo[w][c] < d) continue;
        if(w == n){
            ans = min(ans, d);
            continue;
        }

        for(auto &v : W[w]){
            if(c+v.c <= limit and memo[w][c] + v.d <= ans)
            if(memo[w][c] + v.d < memo[v.v][c+v.c]){
                memo[v.v][c+v.c] = memo[w][c] + v.d;
                heap.push({v.v, c+v.c, memo[v.v][c+v.c]});
            }
        }
    }
    if(ans>=INF)
        cout << "Poor KCM\n";
    else
        cout << ans << endl;
    return;
} 

// main 함수는 동일
```



3. BFS의 재발견 : 알고리즘 수업시간때 BFS로는 weighted Tree의 최단 경로를 구할 수 없다고 배운다. 이 말은 반은 맞고 반은 틀린 말이다. BFS로 알고리즘 문제를 풀경우 시간 초과로 인해서 문제를 틀리게 되니 맞는 말이다. 하지만 해법 자체가 틀린 것은 아니니 또 틀린말이 되게 된다. 따라서 반은맞고(풀수는있지만) 반는 틀린(시간초과)말이 된다. 그렇다면 왜 시간초과가 나게 될까? 이건 dijkstra 알고리즘을 자세히 들여다봐야 한다. 다익스트라 알고리즘은 BFS와는다르게 모든 경우의 수를 다 고려 하지 않는다. 왜냐하면 cost 순서대로 정렬하기 때문이다. 가장 낮은 코스트의 노드를 먼저 탐색한 뒤에 해당 코스트의 노드를 더 높은 코스트의 패스로 접근할 경우 가지치기를 하기 때문에 시간 단축이 된다. 하지만 이와 다르게 BFS는 코스트 순서대로 정렬하지 않는다. 따라서 A-B-C보다 A-C가 더 느린 길이라고 할지라도 목적지에 도착할 때 까지 A-C-.... 로 이루어진 모든 길을 탐색하게 된다. 이는 모든 경우의 수를 푸는 문제에 적합하다고 할 수 있다. 이번 KCM 문제가 딱 이 경우이다. KCM 문제는 모든 경우의 수를 정직하게 탐색하는 문제이다. 이 문제에서 괜한 소팅은 시간을 더 많이 잡아 먹을 뿐이다. 따라서 소팅을 하지 않고 가지치키에 도움이 되는 DP를 사용해서 문제를 해결하는 것이 2번 정답에 비해서 10배가랑 더 빠른 정답을 얻을 수 있다. 

```cpp
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

struct flight{
    int v;
    int c;
    int d;
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

// main 함수는 동일
```

