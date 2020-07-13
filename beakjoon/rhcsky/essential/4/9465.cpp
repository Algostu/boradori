#include <bits/stdc++.h>
using namespace std;

vector<int> dp[2];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        dp[0].resize(N+2); dp[1].resize(N+2);
        fill(dp[0].begin(),dp[0].end(),0);
        fill(dp[1].begin(),dp[1].end(),0);

        for (int i = 0; i < 2; i++)
            for (int j = 2; j < N+2; j++)
                cin >> dp[i][j];
        
        for (int j = 2; j < N+2; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                if(i==1) dp[i][j] += max(dp[i-1][j-1],dp[i-1][j-2]);
                else dp[i][j] += max(dp[i+1][j-1],dp[i+1][j-2]);
            }
            
        }
        cout << max(dp[0][N+1],dp[1][N+1]) << endl;
    }
    return 0;
}