#include <bits/stdc++.h>

using namespace std;

inline int dist(pair<int, int> p1, pair<int, int> p2){
    return pow(abs(p1.first-p2.first), 2) + pow(abs(p1.second-p2.second), 2);
}

bool cmp(pair<int, int> const &a, pair<int, int> const &b){
    return a.second < b.second;
}

int findCenterMinDist(vector<pair<int, int>> &P, int *X, int start, int end, int min_val){
    if(start > end) return 1000000000;
    if(end > 10000) end = 10000;
    sort(&P[X[start-1]], &P[X[end]], cmp);
    for(int i=X[start-1]; i<X[end]-1; i++){
        int j=i;
        while(dist(P[j], P[j+1]) < min_val){
            min_val = dist(P[j], P[j+1]);
            if(j==X[end]-2)break;
            j++;
        }
    }
    sort(&P[X[start-1]], &P[X[end]]);
    return min_val;
}

int findMinDist(vector<pair<int, int>> &P, int *X, int start, int end){
    if(start == end){
        int min_val = 1000000000;
        if(X[start-1]+1 < X[start]){
            sort(&P[X[start-1]], &P[X[start]], cmp);
            for(int i = X[start-1]; i<X[start]-1; i++){
                int local_dist = dist(P[i], P[i+1]);
                //cout << local_dist << endl;
                if(min_val > local_dist){
                    min_val = local_dist;
                }
            }
            sort(&P[X[start-1]], &P[X[start]]);
        }
        // printf("(%d, %d) -> min_val: %d\n", start, end, min_val);
        return min_val;
    } else {
        int mid = (int)floor((start+end)/2.0);
        // printf("(%d, %d) -> left: (%d, %d), right: (%d, %d)\n", start, end, start, mid, mid + 1, end);

        int left_min = findMinDist(P, X, start, mid);
        int right_min = findMinDist(P, X, mid+1, end);
        int min_val = min(left_min, right_min);
        int min_div = min(mid - start + 1, (int)sqrt(min_val));
        int center_min = findCenterMinDist(P, X, mid - min_div + 1, mid + min_div, min_val);
        // printf("(%d, %d) -> center: (%d, %d) -> min value: %d\n", start, end, mid - min_div+ 1, mid + min_div, min(min_val, center_min));
        return min(min_val, center_min);
    }
}

int solve(){
    int N; 
    cin >> N;
    vector<pair<int, int>> P(N, make_pair(0, 0));
    for(int i=0; i<N; i++){
        scanf("%d %d", &P[i].first, &P[i].second);
    }
    
    sort(&P[0], &P[N]);
    int arr[20005];
    int * x = &arr[10001];
    for(int i=-10000; i<=10000; i++){
        x[i] = 0;
    }
    for(int i=0; i<N; i++){
        x[P[i].first]++;
    }
    for(int i=-9999; i<=10000; i++){
        x[i] += x[i-1];
    }
    
    return findMinDist(P, x, P[0].first, P[N-1].first);
}


int main(void){

    // int N;
    // cin >> N;

    // for(int i=0; i<N; i++){
    //     int pred;
    //     pred = solve();
    //     int ans;
    //     printf("pred: %d\n", pred);
    //     cin >> ans;
    //     assert(ans == pred);
    //     printf("Test Case %d: correct\n", i+1);
    // }
    cout << solve() << "\n";
    return 0;
}



    

