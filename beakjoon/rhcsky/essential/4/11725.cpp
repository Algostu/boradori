#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;  // Parent,Child

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> N;
    v.resize(N);

    int x, y;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;

        if (x == 1) {
            v[i].first = x;
            v[i].second = y;
        } else if (y == 1) {
            v[i].first = y;
            v[i].second = x;
        } else {
            for (int i = 0; i < v.size(); i++) {
                if (v[i].first == x) {
                    v[i].second = y;
                } else if (v[i].first == y) {
                    v[i].second = y;
                }
            }
        }
    }

    for (auto &&i : v) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}