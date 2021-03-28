#include <bits/stdc++.h>

using namespace std;

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n), dp(n, 1), prev(n, -1);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i] and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int max_idx, max_val=0;
    for(int i=0; i<n; i++){
        if(dp[i] > max_val){
            max_val = dp[i], max_idx = i;
        }
    }
    stack<int> st;
    cout << max_val << endl;
    while(max_idx!=-1){
        st.push(arr[max_idx]);
        max_idx = prev[max_idx];
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}