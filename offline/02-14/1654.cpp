// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

inline long long splitN(vector<int> &arr, int N){
    long long sum = 0;
    int size = arr.size();
    for(int i=0; i<size; i++){
        sum += arr[i] / N;
    }
    return sum;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> arr(k);
    int max_val = 0;
    for(int i=0; i<k; i++){
        scanf("%d", &arr[i]);
        max_val = max(max_val, arr[i]);
    }
    int m = 1;
    long long l = 2;
    long long r = max_val;
    int size = arr.size();

    while(l <= r){
        long long c_m = (l + r)/2;
        long long t = 0;
        for(int i=0; i<size; i++){
            t += arr[i]/c_m;
        }
        if(t >= n){
            m = c_m;
            l = c_m+1;
        } else {
            r = c_m-1;
        }
    }

    cout << m << "\n";

    return 0; 
}