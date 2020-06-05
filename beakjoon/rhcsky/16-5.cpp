#include <iostream>
#include <vector>

using namespace std;

int n;
int RGB[1001][3];
vector<int> cost;
bool visit[1001] = {false,};
void RGB_DFS(int);

int main()
{
    cin >> n;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",RGB[i][j]);
        }
    }
    return 0;
}

void RGB_DFS(int cnt){
    
}