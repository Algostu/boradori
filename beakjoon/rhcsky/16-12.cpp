#include <iostream>
using namespace std;

int main()
{
    int n, sum=0;
    int arr[1001], dp[1001], rdp[1001];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i+1; j++)
        {
            if(arr[i]>arr[j] && dp[i] < dp[j]+1) dp[i]++;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        rdp[i] = 1;
        for (int j = n-1; j >= i; j--)
        {
            if(arr[i]>arr[j] && rdp[i] < rdp[j]+1) rdp[i]++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(dp[i]+rdp[i] > sum) sum = rdp[i] + dp[i];
    }
    
    cout << sum-1;

    return 0;
}