// Created on ���Ѱ��� iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, s, e, ans, i, j;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    s=0, e=n-1, ans=INT_MAX;
    while(s<e){
        if (abs(ans) > abs(a[s]+a[e])){
            ans = a[s] + a[e];
            i = s, j = e;
        }

        if(a[s]+a[e]<=0) s++;
        else e--;
    }
    cout << a[i] << " " << a[j] << endl;
    return 0;
}
