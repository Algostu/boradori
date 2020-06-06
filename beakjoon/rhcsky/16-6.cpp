#include <iostream>
using namespace std;

int main()
{
    int n, maxi=0;
    int dp[501][501];

    scanf("%d", &n);

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            scanf("%d",&dp[i][j]);
        }
    }
    for (int i = 2; i < n+1; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            if(j==1) dp[i][j] += dp[i-1][j];
            else if(j==n) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        if(dp[n][i] > maxi) maxi = dp[n][i];
    }

    cout << maxi;

    return 0;
}