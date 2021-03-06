#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 301;

pair<int, int> dirs[] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int t, l, sx, sy, tx, ty, x, y, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> l >> sx >> sy >> tx >> ty;

        bool visit[l + 1][l + 1] = {
            false,
        };
        queue<tuple<int, int, int>> q;  //time,x,y
        q.push({0, sx, sy});
        visit[sx][sy] = true;

        while (!q.empty()) {
            cnt = get<0>(q.front());
            x = get<1>(q.front());
            y = get<2>(q.front());
            q.pop();

            if (x == tx && y == ty) {
                cout << cnt << '\n';
                break;
            }

            for (auto &&dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && ny >= 0 && nx < l && ny < l && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    q.push({cnt + 1, nx, ny});
                }
            }
        }
    }
    return 0;
}