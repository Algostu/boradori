#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    int s, e, minValue, ans;
    sort(arr.begin(), arr.end());
    minValue = INT_MAX;
    s = 1, e = 2, ans = arr[1] - arr[0];
    if(ans>=M) minValue = min(minValue, ans);
    while(s<N){
        cout << s << " " << e << " " << minValue << endl;
        if(ans>=M or e==N) { ans-=(arr[s]-arr[s-1]); s++; }
        else { ans+=(arr[e]-arr[e-1]); e++; }
        if(ans>=M) minValue = min(minValue, ans);
    }
    cout << minValue << endl;
    return 0;
}
