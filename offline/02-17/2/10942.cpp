#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int main(void){
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    matrix dp(n+1, vector<int>(n+1, 1));
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int d=1; d<=n/2; d++){
        for(int mid = d+1; mid+d<=n; mid++){
            int start = mid-d;
            int end = mid+d;
            if(dp[start+1][end-1] == 1 and a[start] == a[end])
                dp[start][end] = 1;
            else
                dp[start][end] = 0;
        }

        for(int mid = d; mid+d<=n; mid++){
            int start = mid-d+1;
            int end = mid + d;
            if(dp[start+1][end-1] == 1 and a[start] == a[end])
                dp[start][end] = 1;
            else
                dp[start][end] = 0;
        }
    }


    
    cin >> m; 
    
    for(int i=0; i<m; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
    return 0;
}
