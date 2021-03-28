#include <bits/stdc++.h>

using namespace std;

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, cnt=0, tmp;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(arr.empty() or arr.back() < tmp){
            cnt++; arr.push_back(tmp);
        } else {
            auto it = lower_bound(arr.begin(), arr.end(), tmp);
            *it = tmp;
        }
    }
    cout << cnt << endl;
    return 0;
}