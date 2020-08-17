#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,input;
    int x1,x2,y1,y2;
    cin >> N >> M;
    int table[N+2][N+2];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            table[i+1][j+1] = table[i+1][j]  + table[i][j+1] - table[i][j] + input;
        }
    }
    while (M--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1] << '\n';
    }
    return 0;
}