// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, d, k, c, cnt=0;
    cin >> n >> d >> k >> c;
    vector<int> arr(n), ss(d+1, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<k; i++) {
        ss[arr[i]] += 1;
        if(ss[arr[i]] == 1) cnt += 1;
    }
    int ans=0, s=0, e=k;
    ans = cnt + (ss[c] > 0 ? 0 : 1);
    while(s<n){
        ss[arr[e]] += 1;
        if(ss[arr[e++]] == 1) cnt+=1;
        ss[arr[s]] -= 1; 
        if(ss[arr[s++]] == 0) cnt-=1;
        if(e == n) e = 0;
        ans = max(ans, cnt + (ss[c] ? 0 : 1) );
    }
    cout << ans << endl;
    return 0;
}