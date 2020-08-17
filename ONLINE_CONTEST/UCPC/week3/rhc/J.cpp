#include<bits/stdc++.h>
using namespace std;

int N;
pair<int,int> coord[1001];
int D[1005][2];

inline int cal_distance(pair<int,int> c1, pair<int,int> c2){
    return pow(c1.first-c2.first,2) + pow(c1.second-c2.second,2);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 0, min = INT_MAX;
    int N, x, y, dist;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        coord[i] = {x,y};
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            dist = cal_distance(coord[i],coord[j]);
            if (D[i][0] < dist){
                D[i][0] = dist;
                D[i][1] = j;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (min > D[i][0]) {
            min = D[i][0];
            ans = i;
        }
    }
    
    cout << coord[ans].first << ' ' << coord[ans].second;
    
    return 0;
}
