#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

void solve(){
    int N, M;

    cin >> N >> M;

    lld period = 0;

    int f_0 = 0;
    int f_1 = 1;

    do {
        int temp = (f_0 + f_1) % M;
        f_0 = f_1;
        f_1 = temp;
        period++;
    }while(!(f_0==0 && f_1==1));

    printf("%d %lld\n", N, period);
    return;
}

int main(void){

    int T;
    cin >> T;
    for(int i = 0; i<T; i++){

        solve();
    }

    return 0;
}
