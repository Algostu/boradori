// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int min_cost[n+1];
    int prev[n+1];

    memset(prev, 0, sizeof prev);
    memset(min_cost, 0, sizeof min_cost);

    for(int i=1; i<=n; i++){
        int next[3] = { i+1, i*2, i*3 };
        for(int j=0; j<3; j++){
            if(next[j] <= n and (min_cost[next[j]] == 0 or min_cost[next[j]] > min_cost[i] + 1)){
                min_cost[next[j]] = min_cost[i] + 1;
                prev[next[j]] = i;
            }
        }
    }

    cout << min_cost[n] << endl;
    while(n != 0){
        cout << n << " ";
        n = prev[n];
    }
    cout << endl;
    return 0;
}