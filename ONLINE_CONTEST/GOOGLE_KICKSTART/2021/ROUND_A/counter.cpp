#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

template <typename T>
void direction_counter(bool row_first, const T& rows, const T& cols, matrix & my_map, matrix & dir){
    
    for(const auto & row : rows)
    {
        int cnt = 0;
        for(const auto & col : cols){
            int i = row_first ? row : col;
            int j = !row_first ? row : col;
            if(my_map[i][j]) cnt++;
            else cnt = 0;
            dir[i][j] = cnt;
        }
    }
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    matrix my_map = { {1, 1, 0, 0, 0 }, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}};
    matrix left(5, vector<int>(5, 0)), right(5, vector<int>(5, 0)), bottom(5, vector<int>(5, 0)), top(5, vector<int>(5, 0));
    
    vector<int> dir1(5), dir2(5);
    for (size_t i = 0; i < 5; i++)
    {
        dir1[i] = dir2[i] = i;
    }
    
    direction_counter(true, dir1, dir2, my_map, left);
    reverse(dir2.begin(), dir2.end());
    direction_counter(true, dir1, dir2, my_map, right);
    direction_counter(false, dir1, dir2, my_map, bottom);
    reverse(dir2.begin(), dir2.end());
    direction_counter(false, dir1, dir2, my_map, top);
    
    return 0;
}