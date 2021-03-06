#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1000000000;

int N;
int arr[501][2], dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i + j][1]);
            }
        }
    }

    cout << dp[1][N];

    return 0;
}