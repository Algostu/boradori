// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

typedef struct point_{
    int first;
    int second;
} point;

typedef struct comp{
    bool is_first;
    comp(bool f): is_first(f) {}
    bool operator() (pair<int, int> const &a, pair<int, int> const &b){
        return (this->is_first ? a.first < b.first : a.second < b.second);
    }
} comp;

inline int dist(pair<int, int> p1, pair<int, int> p2){
    return pow(abs(p1.first-p2.first), 2) + pow(abs(p1.second-p2.second), 2);
}

int findMin(vector<pair<int, int>>::iterator it, int n){
    if(n == 2){
        return dist(it[0], it[1]);
    } else if(n == 3){
        return min({dist(it[0], it[1]), dist(it[0], it[2]), dist(it[1], it[2])});
    }
    int mid = n/2;
    int line = (it[mid-1].first + it[mid].first)/2;
    int min_dist = min(findMin(it, mid), findMin(it + mid, n-mid));
    
    vector<pair<int, int>> center;
    center.reserve(n);

    for(int i=0; i<n; i++){
        if((it[i].first-line)*(it[i].first-line) < min_dist){
            center.push_back(it[i]);
        }
    }

    sort(center.begin(), center.end(), comp(false));

    int center_size = center.size();

    for(int i=0; i<center_size-1; i++){
        for(int j=i+1; j<center_size && pow(abs(center[i].second-center[j].second), 2) < min_dist; j++){
            min_dist = min(min_dist, dist(center[i], center[j]));
        }
    }

    return min_dist;
}

int solve(){
    int N;
    cin >> N;
    vector<pair<int, int>> p(N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    
    sort(p.begin(), p.end(), comp(true));

    return findMin(p.begin(), N);
}

int main() {
    // int N;
    // cin >> N;
    // for(int i=0; i<N; i++){
    //     cout << solve() << "\n";
    //     int ans;
    //     cin >> ans;
    // }

    cout << solve() << "\n";
}