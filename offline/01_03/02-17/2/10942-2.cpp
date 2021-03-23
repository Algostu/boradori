#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int pal(matrix &dp, vector<int> &a, int s, int e){
    if (s >= e)
        return 1;
    else if (dp[s][e] != -1)
        return dp[s][e];
    else if (a[s] != a[e])
        return dp[s][e] = 0;
    else {
        return dp[s][e] = pal(dp, a, s+1, e-1);
    }
}

int main(void){
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    matrix dp(n+1, vector<int>(n+1, -1));
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    
    cin >> m; 
    
    for(int i=0; i<m; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", pal(dp, a, s, e));
    }
    return 0;
}
