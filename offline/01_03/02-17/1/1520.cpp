#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(matrix & h, matrix &a, int m, int n){
    if(m==1 and n==1)
        return 1;
    if(a[m][n] != -1){
        return a[m][n];
    } else {
        a[m][n] = 0;
        for(int i=0; i<4; i++){
            int x = m + dx[i];
            int y = n + dy[i];

            if(h[x][y] <= h[m][n]) continue;

            a[m][n] += dfs(h, a, x, y);
        }
    }
    return a[m][n];
}

int main(void){
    int m, n;
    cin >> m >> n;
    matrix h(m+3, vector<int>(n+3, 0));
    matrix a(m+3, vector<int>(n+3, -1));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &h[i][j]);
        }
    }
    cout << dfs(h, a, m, n) << "\n"; 
    return 0;
}
