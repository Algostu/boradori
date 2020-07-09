#include <bits/stdc++.h>
using namespace std;

pair<int, int> m[51][51];  // cabbage, visit
int r[4] = {1, -1, 0, 0};
int c[4] = {0, 0, 1, -1};
int T, M, N, K;

void dfs(int i, int j) {
  m[i][j].second = 1;
  for (int k = 0; k < 4; k++) {
    int x = j + c[k];
    int y = i + r[k];
    if (m[y][x].first == 1 && m[y][x].second == 0 && y >= 0 && y < N &&
        x >= 0 && x < M) {
      dfs(y, x);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
  int a, b;
  cin >> T;
  while (T--) {
    cin >> M >> N >> K;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        m[i][j].first = 0;
        m[i][j].second = 0;
      }
    }

    for (int i = 0; i < K; i++) {
      cin >> a >> b;
      m[b][a] = {1, 0};
    }

    int cnt{};

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (m[i][j].first == 1 && m[i][j].second == 0) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}