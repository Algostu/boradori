#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, l;
    cin >> n >> l ;
    vector<int> m(n+1), c(n+1), dp(10001);
    for(int i=1; i<=n; i++) cin >> m[i];
    for(int i=1; i<=n; i++) cin >> c[i];

    int s = 0;
    for(int i=1; i<=n; i++){
        for(int cost = s; cost >= 0; cost--){
            dp[cost + c[i]] = max(dp[cost + c[i]], dp[cost]+m[i]);
        }
        s+=c[i];
    }

    for(int i=0; i<=s; i++){
        if(dp[i] >= l){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
