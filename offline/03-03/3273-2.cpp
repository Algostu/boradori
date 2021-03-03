// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int freq[1000001];

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, cnt=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}
    cin >> m;
    for(int i=0; i<n; i++)
        if(m>a[i] and freq[m-a[i]]) cnt++;
    cout << cnt/2 << endl;
    return 0;
}