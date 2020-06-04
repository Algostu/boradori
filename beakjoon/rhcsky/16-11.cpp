#include <iostream>
using namespace std;

int main()
{
    int n, cnt=0;
    int arr[1001], dp[1001]= {0,};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(arr[i]>arr[j] && dp[j]+1 > dp[i]) dp[i]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(dp[i]>cnt) cnt = dp[i];
    }
    
    cout << cnt;

    return 0;
}