#include <bits/stdc++.h>
using namespace std;

int m[11] = {0,};

int DP(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    return m[n] = DP(n-1) + DP(n-2) + DP(n-3);
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T,N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << DP(N) << endl;
    }
    
    return 0;
}