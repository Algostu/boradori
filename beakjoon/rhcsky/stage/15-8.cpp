#include <iostream>
using namespace std;

bool check[21] = {false, };
int board[21][21];
int n, mini = 2147483647;

void DFS(int, int);

int main()
{
    cin >> n;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cin >> board[i][j];
        }
    }
    DFS(0,1);
    cout << mini << endl;    
    return 0;
}

void DFS(int cnt, int a){
    if(cnt==n/2){
        int start, link, temp;
        start = link = 0;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                if(check[i] && check[j]) start += board[i][j];
                if(!check[i] && !check[j]) link += board[i][j];
            }
        }
        temp = abs(start-link);
        if(temp < mini) mini = temp;
        return;
    }
    for (int i = a; i < n; i++)
    {
        check[i] = true;
        DFS(cnt+1,i+1);
        check[i] = false;
    }
}