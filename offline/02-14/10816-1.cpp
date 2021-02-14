#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    // ascending sort
    sort(arr.begin(), arr.end());
    
    // print frequency
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int temp;
        scanf("%d", &temp);
        auto lower = lower_bound(arr.begin(), arr.end(), temp);
        auto upper = upper_bound(arr.begin(), arr.end(), temp);
        printf("%d ", (int)(upper - lower));
    }
    return 0;
}