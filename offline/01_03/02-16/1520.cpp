// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

inline void update(matrix &h, matrix &a, int r, int c){
    int ans = 0;
    int me = h[r][c];
    if(me < h[r+1][c]) ans += a[r+1][c];
    if (me < h[r-1][c]) ans += a[r-1][c];
    if (me < h[r][c+1]) ans += a[r][c+1];
    if (me < h[r][c-1]) ans += a[r][c-1];

    a[r][c] = max(a[r][c], ans);
} 

int main() {
    int m, n;
    cin >> m >> n;
    matrix h(m+3, vector<int>(n+3, 2e9));
    matrix a(m+3, vector<int>(n+3, 0));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &h[i][j]);
        }
    }

    a[1][1] = 1;

    for(int r=1; r<=m; r++){
        for(int c=1; c<=n; c++){
            update(h, a, r, c);
        }
    }

    for(int r=1; r<=m; r++){
        for(int c=n; c>=1; c--){
            update(h, a, r, c);
        }
    }

    for(int r=m; r>=1; r--){
        for(int c=1; c<=n; c++){
            update(h, a, r, c);
        }
    }

    for(int r=m; r>=1; r--){
        for(int c=n; c>=1; c--){
            update(h, a, r, c);
        }
    }

    for(int c=1; c<=n; c++){
        for(int r=1; r<=m; r++){
            update(h, a, r, c);
        }
    }

    for(int c=1; c<=n; c++){
        for(int r=m; r>=1; r--){
            update(h, a, r, c);
        }
    }

    for(int c=n; c>=1; c--){
        for(int r=1; r<=m; r++){
            update(h, a, r, c);
        }
    }

    for(int c=n; c>=1; c--){
        for(int r=m; r>=1; r--){
            update(h, a, r, c);
        }
    }

    cout << a[m][n] << "\n";

    return 0;
}