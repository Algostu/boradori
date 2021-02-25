#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;
vector<int> v_out;
vector<bool> visit;

void travel(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << v_out[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (visit[i]) continue;
        visit[i] = true;
        v_out[idx] = v[i];
        travel(idx + 1);
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);
    v_out.resize(N);
    visit.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        visit[i] = false;
    }

    sort(v.begin(), v.end());

    travel(0);

    return 0;
}