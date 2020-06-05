#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, a, b, maxi = 0;
    vector<pair<int,int>> line;
    int dp[101];

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        line.push_back({a,b});
    }

    sort(line.begin(), line.end());

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i+1; j++)
        {
            if(line[i].second > line[j].second && dp[i] < dp[j]+1) dp[i]++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(dp[i]>maxi) maxi = dp[i];
    }
    
    cout << n-maxi;
    
    return 0;
}