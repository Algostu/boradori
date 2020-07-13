#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int tomato[1001][1001];
int v[1001][1001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    int M, N, res{};
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tomato[i][j];
            v[i][j] = -1;
            if (tomato[i][j] == 1)
            {
                q.push({i, j});
                v[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (tomato[nx][ny] == 0 && v[nx][ny] == -1)
                {
                    v[nx][ny] = v[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            res = max(res, v[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tomato[i][j] == 0 && v[i][j] == -1)
            {
                res = -1;
            }
        }
    }
    
    cout << res << endl;

    return 0;
}
