#include <bits/stdc++.h>
using namespace std;

bool sortsec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}
int main() {

    int N, min, cnt=0;

    cin >> N;
    vector<pair<int,int>> v;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), sortsec);

    min = v[0].second;
    cnt++;

    for (int i = 1; i < N; i++) {
        if (v[i].first >= min) {
            min = v[i].second;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}