#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    int s, e, cnt, ans;
    cnt = INF;
    s = e = ans = 0;
    while(s<N){
        if(ans>=M or e==N) { ans-=arr[s]; s++; }
        else { ans+=arr[e]; e++; }
        if(ans>=M) cnt = min(cnt, e-s);
    }
    cout << (cnt==INF?0:cnt) << endl;
    return 0;
}
