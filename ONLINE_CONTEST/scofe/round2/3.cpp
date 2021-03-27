#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 5001

int parent[MAX_NODE];
bool leaf[MAX_NODE];
vector<int> children[MAX_NODE];

int find(int u)
{
    // 루트 노드이면 return u
    if (u == parent[u])
        return u;
 
    // 그 외에는 자신의 루트를 찾으러 간다.
    return find(parent[u]);
}

void append_child(int u, int target)
{
    children[u].push_back(target);
    // 루트 노드이면 return u
    if (u == parent[u])
        return;
    else
        append_child(parent[u], target);
}

void merge(int u, int v)
{
    int u_p = find(u);
    int v_p = find(v);
 
    // 루트가 같다면 이미 같은 트리
    if (u_p == v_p){
        parent[v] = u;
    }
    else {
        parent[v_p] = u;
    }
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        leaf[i] = true;
    }

    for (int i = 1; i <= N-1; i++)
    {
        int h, l;
        cin >> h >> l;
        leaf[h] = false;
        merge(h, l);
    }

    for (int i=1; i<=N; i++){
        if(leaf[i]){
            append_child(parent[i], i);
        }
    }

    for (int i=1; i<=N; i++){
        if(!leaf[i]){
            sort(children[i].begin(), (children[i]).end());
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int h, l;
        cin >> h >> l;
        cout << (lower_bound(children[h].begin(), children[h].end(), l) != children[h].end() ? "yes" : "no") << endl;
    }

    return 0;
}