#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

int solve(){
    int N;
    cin >> N;
    matrix a(N+1, vector<int>(N+1, INT_MAX));
    vector<int> b(N+1, 0);
    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        a[i][i] = 0;
        b[i] += b[i-1] + temp;
    }
    
    for(int end=2; end<=N; end++){
        for(int start=end-1; start>0; start--){
            for(int mid=start; mid<end; mid++){
                int value = b[end] - b[start-1] ;
                int cost = value + a[start][mid] + a[mid+1][end];
                if (cost < a[start][end]){
                    a[start][end] = cost;
                }

            }
        }
    }

    return a[1][N];

}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cout << solve() << "\n";
    }
    return 0;
}

