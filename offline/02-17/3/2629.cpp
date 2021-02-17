#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int dp[15001][31];
int a[31];

void check(int cw, int i){
    if(i == -1) return;
    int & result = dp[cw][i];
    if(result == -1)
        return;
    else
        result = 1;
    check(cw+a[i], i-1);
    check(abs(cw-a[i]), i-1);
    check(cw, i);
}

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    check(0, n);

    cin >> m;
    for(int i=0; i<m; i++){
        char ans;
        int left = 0;
        cin >> left;
        if(left > 15000) ans = 'N';
        else 
            ans = dp[left][0] > 0 ? 'Y' : 'N';
        cout << ans;
        cout << " ";
    }
    cout << "\n";
}


