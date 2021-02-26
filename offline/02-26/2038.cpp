// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> qu;
    int k, f_k, q;
    k = f_k = q = 1;
    while(q <= n){
        if(!qu.empty() and k == qu.front()){
            f_k++; qu.pop();
        }
        q += f_k;
        qu.push(q);
        k++;    
    }
    cout << (k-1) << endl;
    return 0;
}