nclude <bits/stdc++.h>

using namespace std;

int main(void){
    int n; 
    cin >> n;
    vector<int> dp(n, 1);
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]+1);
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}
