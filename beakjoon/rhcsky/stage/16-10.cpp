#include <iostream>
using namespace std;

int main () {

    int n, sum = 0;

    scanf("%d", &n);
    int graph[10003] = { 0, };
    int dp[10003] = { 0, };

    for (int i = 3; i < n+3; i++) scanf("%d", &graph[i]);

    for (int i = 3; i < n+3; i++) {
        dp[i] = max(dp[i-3] + graph[i-1] + graph[i], dp[i-2] + graph[i]);
        dp[i] = max(dp[i-1], dp[i]);
        sum = max(sum, dp[i]);
    }

    cout << sum;

    return 0;
}