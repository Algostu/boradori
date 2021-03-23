#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    // sort by ascending order
    sort(arr.begin(), arr.end());
    
    long long m = 1;
    long long l = 2;
    long long r = (arr[n-1] - arr[0]) / (c-1);
    
    while(l <= r){
        long long e = (l + r) / 2;
        long long t = 0;
        long long y = arr[0];
        for(int i=0; i<n; i++){
            if(y <= arr[i]){
                t+=1;
                y = arr[i] + e;
            }
        }
        // printf("e: %d, t: %d\n", e, t);
        if(t < c){
            r = e-1;
        } else {
            m = e;
            l = e+1;
        }
    }
    
    cout << m << "\n";
}