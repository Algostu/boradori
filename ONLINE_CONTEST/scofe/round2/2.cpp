#include <bits/stdc++.h>
#define MAX_NODE 20001

using namespace std;

typedef pair<int, int> pii;
 
vector<pii> vc[MAX_NODE];

void prim(int start)
{
    bool visit[MAX_NODE] = {false,};
    visit[start] = true;
 
    // 우선 순위 큐(최소 힙)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
 
    // 1번 정점을 시작점으로 한다.
    for (int i = 0; i < vc[start].size(); i++)
    {
        // 정점과 가중치를 priority_queue에 넣어준다.
        int next = vc[start][i].first;
        int nextCost = vc[start][i].second;
 
        pq.push(pii(nextCost, next));
    }
 
    int ans = 0;
 
    while (!pq.empty())
    {
        int here = pq.top().second;
        int hereCost = pq.top().first;
 
        pq.pop();
 
        // 이미 방문한 정점은 무시한다.
        if (visit[here])
            continue;
 
        visit[here] = true;
 
        ans += hereCost;
 
        // 다음 정점을 우선순위 큐에 넣어준다.
        for (int i = 0; i < vc[here].size(); i++)
        {
            int there = vc[here][i].first;
            int thereCost = vc[here][i].second;
 
            pq.push(pii(thereCost, there));
        }
    }
 
    printf("%d", ans);
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    map<string, int> convertor;
    cin >> N;
    int id = 0;
    for (size_t i = 0; i < N; i++)
    {
        string u, v, cost;
        int from, to, val;
        cin >> u >> v >> cost;
        val = atoi(cost.c_str());
        if(convertor.find(u) == convertor.end()){
            from = id;
            convertor.insert({u, id++});
        } else {
            from = convertor.find(u)->second;
        }
        if(convertor.find(v) == convertor.end()){
            to = id;
            convertor.insert({v, id++});
        } else {
            to = convertor.find(v)->second;
        }
        vc[from].push_back(pii(to, val));
        vc[to].push_back(pii(from, val));
    }
    
    prim(1);
    
    return 0;
}