#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

ostream& operator<<(ostream& os, const matrix& m)
{
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            os << m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

template <typename T>
void direction_counter(bool row_first, const T & first, const T & second, matrix & my_map, matrix & dir){
    for(const auto & f : first){
        int cnt = 0;
        for(const auto & s : second){
            int i = row_first ? f : s;
            int j = !row_first ? f : s;
            if(my_map[i][j]) cnt++;
            else cnt = 0;
            dir[i][j] = cnt;
        }
    }
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    matrix my_map = { {1, 1, 0, 0, 0 }, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}, {1, 1, 1, 0, 0}};

    vector<int> first(5), second(5);
    for (size_t i = 0; i < 5; i++)
    {
        first[i] = second[i] = i;
    }

    matrix top(5, vector<int>(5, 0));

    direction_counter(false, first, second, my_map, top);
    
    cout << my_map;
    cout << top;

    return 0;
}