// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

inline long long order(long long n, long long c){
    long long s = 0;
    c = c*c - 1;
    for(int i=1; i<=n; i++){
        s += c/i > n ? n : c/i;
    }
    return s;
}

int main() {
    long long n, k;
    cin >> n >> k;

    long long left = 1;
    long long right = n;
    double N = 0;

    while(true){
        long long c = (left + right) / 2;
        long long start = order(n, c);
        long long end = order(n, c+1);
        if(start < k and k <= end){
            k -= start;
            N = c;
            break;
        } else if(end <= k){
            left = c + 1;
        } else {
            right = c - 1;
        }
    }

    vector<int> arr;
    arr.reserve(2*n);
    // cout << N << endl;
    for(int i=1; i<=n; i++){
        int start = ceil(N*N / i);
        int end= (N+1)*(N+1);
        start = start > n ? n+1 : start;
        for(;start*i<end && start<=n; start++){
            arr.push_back(start*i);
        }    
    }

    // for(int i=0; i<arr.size(); i++){
    //     cout << arr[i] << endl;
    // }  

    sort(arr.begin(), arr.end());
    cout << arr[k-1] << "\n";

    return 0;
}