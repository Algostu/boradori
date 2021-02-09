#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long int lld;

typedef vector<vector<lld>> matrix;

inline lld mul(lld a, lld b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

matrix operator*(matrix &a, matrix&b){
    // (M, K) * (K, N) = (M, N) 
    int M, N, K;
    M = a.size();
    N = b[0].size();
    K = b.size();

    matrix result(M, vector<lld>(N));
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<K; k++)
                result[i][j] += mul(a[i][k], b[k][j]);

    return result;
}

lld fibonacci(lld n){
    // (fn+1, fn) = ((1, 1), (1, 0))^(n-1)(1, 1) 
    matrix identity(2, vector<lld>(2));
    matrix A(2, vector<lld>(2));

    for(int i = 0; i<2; i++){
        identity[i][i] = 1;
    }
    
    A[0][0] = A[0][1] = A[1][0] = 1;

    while(n > 0){
        if(n % 2 == 1){
            identity = identity * A;
        }

        A = A * A;
        n /= 2;
    }

    return (identity[1][0]) % MOD;
}

void solve(){
    lld n;

    cin >> n;

    lld f_n = fibonacci(n);

    cout << f_n << endl;
}

int main(void){

    solve();

    return 0;
}
