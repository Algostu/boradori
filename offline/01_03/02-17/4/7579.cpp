#include <bits/stdc++.h>

using namespace std;

int dp[101][10001];
int c[101];
int m[101];

int maxMem(int i, int mC){
    if(i == 0 or mC<0) return 0;
    int &result = dp[i][mC];
    if(result != -1) return result;
    result = maxMem(i-1, mC);
    if(c[i] <= mC)
        result = max(result, m[i] + maxMem(i-1, mC-c[i]));
    return result;
}

int main(void){
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
   
    int n, M;
    cin >> n >> M;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++) cin >> m[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    int l = -1;
    while(true){
        if(maxMem(n, ++l) >= M) break;
    }

    cout << l << endl;

    return 0;
}
