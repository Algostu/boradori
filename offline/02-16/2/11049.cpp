#include <bits/stdc++.h>

using namespace std;

struct shape{
    int m;
    int n;
};

typedef vector<vector<int>> matrix;

int solve(){
    int N;
    cin >> N;
    matrix a(N+1, vector<int>(N+1, INT_MAX));
    vector<shape> s(N+1);
    for(int i=1; i<=N; i++){
        scanf("%d %d", &s[i].m, &s[i].n);
        a[i][i] = 0;
    }
    for(int end=2; end<=N; end++){
        for(int start=end-1; start>0; start--){
            for(int mid=start; mid<end; mid++){
                int value = s[start].m * s[mid].n * s[end].n; 
                int cost = value + a[start][mid] + a[mid+1][end];
                a[start][end] = min(a[start][end], cost);
            }
        }
    }

    return a[1][N];

}

int main(){
    cout << solve() << "\n";
    return 0;
}

