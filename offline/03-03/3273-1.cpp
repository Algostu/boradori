// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    sort(a.begin(), a.end());
    int s, e, cnt, t;
    s=0, e=n-1, cnt=0;
    while(s<e){
        t = a[s]+a[e];   
        if(t == m){ cnt++; s++; e--; }
        else if( t > m ) e--;
        else s++;
    }
    cout << cnt << endl;
    return 0;
}