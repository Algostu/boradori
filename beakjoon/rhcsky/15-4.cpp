#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v;
bool visit[9];
void DFS(int,int);

int main()
{
    cin >> N >> M;
    DFS(0,0);
    return 0;
}

void DFS(int cnt,int idx){
    if(cnt == M){
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx; i < N; i++)
    {   v.push_back(i+1);
        DFS(cnt+1,i);
        v.pop_back();
    }
}