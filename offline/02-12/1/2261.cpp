#include <bits/stdc++.h>

using namespace std;

inline int dist(pair<int, int> p1, pair<int, int> p2){
    return pow(abs(p1.first-p2.first), 2) + pow(abs(p1.second-p2.second), 2);
}

bool cmp(pair<int, int> const &a, pair<int, int> const &b){
    return a.second < b.second;
}

int findCenterMinDist(vector<pair<int, int>> &P, int *X, int start, int end, int min_val){
    
    printf("findCenterMinDist) start:%d, end:%d\n", start, end);
    cout << X[start] << " " << X[end] << endl;
    sort(&P[X[start]], &P[X[end]], cmp);
    for(int i=X[start]; i<X[end]-1; i++){
        int j=i;
        //cout << i << endl;
        while(dist(P[j], P[j+1]) < min_val){
            min_val = dist(P[j], P[j+1]);
            if (j == X[end]-2) break;
            j++;
        }
    }
    sort(&P[X[start]], &P[X[end]]);
    return min_val;
}

int findMinDist(vector<pair<int, int>> &P, int *X, int start, int end){
    if(start == end){
        //printf("findMinDist) start:%d, end:%d\n", start, end);
        int min_val = 1000000000;
        for(int i = X[start-1]; i<X[start]-1; i++){
            //cout << i << endl;
            int local_dist = dist(P[i], P[i+1]);
            if(min_val > local_dist){
                min_val = local_dist;
            }
        }
        return min_val;
    } else {
        //printf("findMinDist2) start:%d, end:%d\n", start, end);
        int mid = (int)floor((start+end)/2.0);
        int left_min = findMinDist(P, X, start, mid);
        int right_min = findMinDist(P, X, mid+1, end);
        int min_val = min(left_min, right_min);
        int min_div = min(mid - start + 1, (int)sqrt(min_val));
        int center_min = findCenterMinDist(P, X, mid - min_div + 1, mid + min_div, min_val);

        return min(min_val, center_min);
    }
}

void solve(){
    int N; 
    cin >> N;
    vector<pair<int, int>> P(N, make_pair(0, 0));
    for(int i=0; i<N; i++){
        scanf("%d %d", &P[i].first, &P[i].second);
    }
    
    sort(&P[0], &P[N]);
    int arr[20002];
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

    cout << findMinDist(P, x, P[0].first, P[N-1].first) << "\n";

    return;
}


int main(void){

    solve();

    return 0;

}
