// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){}
    point(int x, int y): x(x), y(y) {}
    bool operator< (const point & other) const {
        if(this->y == other.y){
            return this->x < other.x;
        } else {
            return this->y < other.y;
        }
    }
};

bool comp(point const & p1, point const & p2){
    return p1.x < p2.x;
}

inline int dist(point const & p1, point const & p2){
    return pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2);
}

int solve() {
    int n;
    cin >> n;
    vector<point> point_vec(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &point_vec[i].x, &point_vec[i].y);
    }
    // sort by x
    sort(point_vec.begin(), point_vec.end(), comp);    

    // init
    int start = 0;
    int ans = dist(point_vec[0], point_vec[1]);
    set<point> candidate = {point_vec[0], point_vec[1]};

    // condition: candidate contain point pow(abs(now.x - cursor.x), 2) < ans
    for(int i=2; i<n; i++){

        // total O(N)
        auto now = point_vec[i];
        while(start < i){
            auto cursor = point_vec[start];
            int x_diff = now.x - cursor.x;
            if(x_diff * x_diff > ans){
                candidate.erase(cursor);
                start++;
            } else {
                break;
            }
        }

        // compare only now.y +- ans
        // logN
        auto lower = candidate.lower_bound({-10000, now.y-(int)sqrt(ans)});
        auto upper = candidate.upper_bound({10000, now.y+(int)sqrt(ans)});
        for(auto it = lower; it != upper; it++){
            ans = min(ans, dist(now, *it));
        }
        candidate.insert(now);
    }
    cout << ans << "\n";
    return ans;
}

int main(){
    // int N;
    // cin >> N;
    // for(int i=0; i<N; i++){
    //     int ans = solve();
    //     int pred = 0;
    //     cin >> pred;
    //     assert(pred == ans);
    //     printf("Test Case %d Correct!\n");
    // }
    solve();
}