#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    arr.push_back(0);
    int cnt = 0;
    int temp;
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        if(temp > arr.back()){
            arr.push_back(temp);
            cnt += 1;
        } else {
            auto it = lower_bound(arr.begin(), arr.end(), temp);
            *it = temp;
        }
    }

    cout << cnt << "\n";

    return 0;

}

