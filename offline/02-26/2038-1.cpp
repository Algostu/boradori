// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;
int i, j, f[2 << 20];
int main() {
    int n; cin >> n;
    f[1] = i = j = 1;
    while(j<n) j+= (f[1+i++] = 1 + f[i+1 - f[f[i]]]);
    cout << i << endl;
    return 0;
}