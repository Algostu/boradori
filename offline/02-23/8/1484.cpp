#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    long long G, s, e, cnt, ans;
    s = 1, e = 2, cnt = 0, ans = 0;
    cin >> G;
    while(s<e){
        if(ans>=G or 2*e-1 > G) { ans -= 2*s+1; s++; }
        else { ans += 2*e-1; e++; }
        if(ans == G) {
            cnt++; cout << e-1 << endl;
        }
    }
    if(!cnt) cout << "-1\n";
    return 0;
}
