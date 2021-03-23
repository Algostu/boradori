#include <bits/stdc++.h>

using namespace std;

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    int m[1001][101] = {0};
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> m[i][j];
        }
    }
    cout << m[1][1] << endl;
    int ans = 0;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            m[i][j] += max(m[i-1][j], m[i][j-1]);
        }
    }
    cout << m[M][N] << endl;
}