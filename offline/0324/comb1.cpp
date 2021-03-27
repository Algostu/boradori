// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r){
    if(r==0 or n==r) return 1;
    else return comb(n-1, r-1) + comb(n-1, r);
}

int main() {
    cout << comb(3, 1) << endl;
    return 0;
}