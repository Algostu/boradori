#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int MAX = 101;

int N, M, H;
bool ripe_all{false};
queue<tuple<int, int, int>> ripe;
int tomato[MAX][MAX][MAX];

tuple<int, int, int> dirs[] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

bool checkRipe() {
    int cnt{};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[j][k][i] == 0) return false;
            }
        }
    }
    return true;
}

void BFS() {
    int cnt{0};

    while (!ripe.empty()) {
        int cur_size = ripe.size();
        cnt++;

        for (int i = 0; i < cur_size; i++) {
            int x = get<0>(ripe.front());
            int y = get<1>(ripe.front());
            int z = get<2>(ripe.front());
            ripe.pop();

            for (auto&& dir : dirs) {
                int nx = x + get<0>(dir);
                int ny = y + get<1>(dir);
                int nz = z + get<2>(dir);

                if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;

                if (!tomato[nx][ny][nz]) {
                    tomato[nx][ny][nz] = 1;
                    ripe.push({nx, ny, nz});
                }
            }
            if (!ripe.size() && checkRipe()) {
                cout << cnt << '\n';
                return;
            } else if (!ripe.size() && !checkRipe()) {
                cout << -1 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> input;
                tomato[j][k][i] = input;
                if (input == 1)
                    ripe.push({j, k, i});
                if (input == 0)
                    ripe_all = false;
            }
        }
    }

    if (ripe_all)
        cout << 0 << '\n';
    else
        BFS();

    return 0;
}