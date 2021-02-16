#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<int, int>>> matrix;

int solve(){
    int N;
    cin >> N;
    matrix a(N+1, vector<pair<int, int>>(N+1, make_pair(100000000, 100000000)));
    for(int i=1; i<=N; i++){
        scanf("%d", &a[i][i].first);
        a[i][i].second = 0;
    }
    for(int end=2; end<=N; end++){
        for(int start=end-1; start>0; start--){
            for(int mid=start; mid<end; mid++){
                int value = a[start][mid].first + a[mid+1][end].first;
                int cost = value + a[start][mid].second + a[mid+1][end].second;
                if (cost < a[start][end].second){
                    a[start][end].first = value;
                    a[start][end].second = cost;
                }

            }
        }
    }

    return a[1][N].second;

}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cout << solve() << "\n";
    }
    return 0;
}

