#include <bits/stdc++.h>

using namespace std;

struct less_than_key {
    bool operator() (const int & a, const int & b){
        return b < a;
    }
};

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    vector<int> test_arr = {1, 2, 3, 4, 5, 6, 7};
    sort(test_arr.begin(), test_arr.end(), less_than_key());
    for(const auto & elem : test_arr){
        cout << elem << endl;
    }
    return 0;
}