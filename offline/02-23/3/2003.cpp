#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M, s=1, e=1, ans=0, cnt=0;
    cin >> N >> M;
    vector<int> arr(N+1);
    for(int i=1; i<=N; i++) cin >> arr[i];
    while(s<=N){ //cout << s << e << endl;
        if(ans>=M or e==N+1){ ans-=arr[s]; s++; }
        else{ ans+=arr[e]; e++; }
        if(ans==M) cnt++;
    }
    cout << cnt << endl;
}
