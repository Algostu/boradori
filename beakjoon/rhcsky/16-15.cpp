#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, input, maxi;
    int dp[100001];
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&input);
        v.push_back(input);
    }

    dp[0] = v[0];
    maxi = dp[0];

    for (int i = 0; i < n; i++)
    {
        dp[i] = max(dp[i-1] + v[i], v[i]);
        maxi = max(dp[i],maxi);
    }
    
    cout << maxi;
    
    return 0;
}