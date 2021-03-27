#include <bits/stdc++.h>

using namespace std;

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    vector<int> test_arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<pair<int, int>> test_pair_arr = { {1, 2}, {2, 3} };
    // this is range based for loop
    // 모든 요소들을 it에 할당한다.
    for(auto & it : test_arr){
        cout << it << endl;
    }

    for(auto & it : test_pair_arr){
        cout << it.first << endl;
    }

    // this is just for loop for cpp stl
    for(auto it = test_arr.begin(); it!=test_arr.end(); ){
        if(*it % 2 == 0) it = test_arr.erase(it);
        else it++;
    }

    // range-based for loop
    for(const auto & elem : test_arr){
        cout << elem << endl;
    }
    return 0;
}

