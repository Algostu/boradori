#include <bits/stdc++.h>

using namespace std;

struct A{
    int row;
    int col;
};

struct comp_key_a {
    bool operator() (const A & a, const A & b){
        return a.row != b.row ? a.row < b.row : a.col < b.col;
    }
};

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    set<A, comp_key_a> my_set;
    
    my_set.insert({1, 2});
    my_set.insert({1, 1});

    for(const auto & elem : my_set){
        cout << elem.row << " " << elem.col << endl;
    }

    return 0;
}