#include <iostream>
using namespace std;

int main(){
    int dp[1001][3], cost[1001][3];
    int n;
    scanf("%d", &n);
    for(int i=1;i<n+1;i++) scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    for (int i = 1; i < n+1; i++)
    {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + cost[i][2];
    }
    cout << min(min(dp[n][0],dp[n][1]),dp[n][2]);    
}


int my_main() // 이건 시간초과 왜???
{
    int num, mini=1000;
    int house[1001][3];
    scanf("%d", &num);
    for (int i = 1; i < num+1; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &house[i][j]);
        }
    }

    house[0][0] = house[0][1] = house[0][2] = 0;

    for (int i = 1; i < num+1; i++)
    {
        house[i][0] += min(house[i-1][1],house[i-1][2]);
        house[i][1] += min(house[i-1][0],house[i-1][2]);
        house[i][2] += min(house[i-1][1],house[i-1][0]);
    }

    for (int i = 0; i < num; i++)
    {
        if(house[num][i]<mini) mini = house[num][i];
    }
    cout << mini;
    return 0;
}