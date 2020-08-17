#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, share, remaind;
    cin >> N;

    share = N/4;
    remaind = N%4;

    if(remaind == 0){
        if(share&1) cout << 4;
        else cout << 2;
    }
    else
    {
        if(share&1){
            if(remaind == 3) cout << 3;
            else if(remaind == 2) cout << 4;
            else cout << 5;
        }
        else{
            cout << remaind;
        }
    }
    
    return 0;
}