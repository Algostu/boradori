// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    int mask = pow(2, arr.size());
    int n = arr.size();
    for(int m = 0; m<mask; m++){
        for(int k = 0; k<n; k++){
            if(m & (1 << k))
                cout << arr[k] << " ";
        }
        cout << endl;
    }
    return 0;
}