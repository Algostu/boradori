#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;
vector<int> v_out;
vector<int> visit;

void travel(int idx, int start_idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << v_out[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = start_idx; i < v.size(); i++) {
        if (visit[i] >= M) continue;
        visit[i]++;
        v_out[idx] = v[i];
        travel(idx + 1, i);
        visit[i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;

    v.resize(N);
    v_out.resize(N);
    visit.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        visit[i] = false;
    }

    sort(v.begin(), v.end());

    travel(0, 0);

    return 0;
}