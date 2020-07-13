#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v;
void DFS(int);

int main()
{
    cin >> N >> M;
    DFS(0);
    return 0;
}

void DFS(int cnt){
    if(cnt == M){
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i < N+1; i++)
    {
        v.push_back(i);
        DFS(cnt+1);
        v.pop_back();
    }
}