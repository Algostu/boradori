#include <iostream>
using namespace std;

int main()
{
    int n, k, w[101], v[101], dp[100001] = {0,};
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
        for (int j = k-w[i]; j >= 0; j--)
        {
            if(dp[j+w[i]] < dp[j] + v[i])
                dp[j+w[i]] = dp[j] + v[i];
        }
    }
    
    cout << dp[k];
    
    return 0;
}