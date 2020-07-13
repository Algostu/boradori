#include <bits/stdc++.h>
using namespace std;

int dp[1001] = {0,};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 2; i < N+1; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    
    cout << dp[N] << endl;
    
    return 0;
}