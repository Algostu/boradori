#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

void solve(){
    lld mod=1000000007;
    lld T = (mod+1)*2;
    lld f_0, f_1, f_2, f_3, n;
    
    f_0 = 0;
    f_1 = 1;
    
    cin >> n;
    n = n%T;
    lld i = 0; 
    for(i = 0; i<n/2; i++){
        f_2 = (f_0 + f_1)%mod;
        f_3 = f_1 + f_2;
        f_0 = f_2%mod;
        f_1 = f_3%mod;
    }
   
    if(n%2 == 0){
        printf("%lld\n", f_0);
    } else{
        printf("%lld\n", f_1);
    }
    return;
}

int main(void){

    solve();

    return 0;
}
