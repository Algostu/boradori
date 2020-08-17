#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <vector>

using namespace std;

map<int, list<list<int>::iterator>> connect_map(map<int, list<int>> & map_iter, map<int, list<int>> & map_target){
  map<int, list<list<int>::iterator>> ans;
  map<int, list<int>::iterator> init;
  
  for(auto& [key, value] : map_iter){
    init[key] = value.begin();
  }

  for(auto& [key, value] : map_target){
    list<list<int>::iterator> target_list;
    for(auto elem : value){
      cout << (*init[elem]) << endl;
      target_list.push_back(init[elem]++);
    }
    ans[key] = target_list;
  }

  return ans;
}

void add_to_map(map<int, list<int>> & m, int a, int b){
    if (m.find(a) == m.end()) {
        m[a] = list<int>();
    }

    m[a].push_back(b);
}

void sort_map(map<int, list<int>> & m){
    for (auto& [key, value] : m) {
        value.sort();
    }
}

void find_map(map<int, list<int>> & m, list<int> ** plist,
    list<int>::iterator & iter, int x, int y){

    *plist = &m[x];

    for (list<int>::iterator i = (*plist)->begin(); i != (*plist)->end(); i++) {
        if(*i == y){
            iter = i;
            break;
        }
    }
}

bool check_end(list<int> ** li, list<int>::iterator & iter, int up){
    // cout << "check_end called\n";
    if(up == 1){
        iter++;
        if(iter == (*li)->end()){
            iter--;
            return 1;
        } else{
            iter--;
            iter = (*li)->erase(iter);
            return 0;
        }
    } else {
        if(iter != (*li)->begin()){
            (*li)->erase(iter--);
            return 0;
        } else {
            return 1;
        }
    }
}

void jump(list<int>::iterator & iter_a, list<int>::iterator & iter_b,
    list<int> ** p_a, list<int> ** p_b, int & x, int & y,
    map<int, list<int>> & m, int up){
    // cout << "jump called\n";
    if(!check_end(p_a, iter_a, up)){
        (**p_b).erase(iter_b);
        x = *iter_a;
        find_map(m, p_b, iter_b, x, y);
    }
}

void print_coor(int a, int b){
    printf("%d %d\n", (a+b)/2, (a-b)/2);
}

int main()
{
    int N, K;
    int x, y;
    string dirs;
    map<int, list<int>> m_plus;
    map<int, list<int>> m_minus;

    cin >> N >> K;

    cin >> dirs;

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int y_zero_minus = a+b, y_zero_plus = a-b;

        add_to_map(m_plus, y_zero_plus, y_zero_minus);
        add_to_map(m_minus, y_zero_minus, y_zero_plus);

        if(i==0){
            y = y_zero_plus;
            x = y_zero_minus;
        }
    }

    sort_map(m_plus); sort_map(m_minus);

    // init cur state
    list<int> * pplus;
    list<int> * pminus;
    list<int>::iterator plus_iter, minus_iter;

    // find_map(m_plus, pplus, plus_iter, y, x);
    find_map(m_minus, &pminus, minus_iter, x, y);
    find_map(m_plus, &pplus, plus_iter, y, x);

    // cout << *plus_iter << endl;
    // cout << *minus_iter << endl;

    map<int, list<list<int>::iterator>> m_iter_minus = connect_map(m_plus, m_minus);
    map<int, list<list<int>::iterator>> m_iter_plus = connect_map(m_minus, m_plus);

    for (auto dir : dirs) {
        // cout << "where : ";
        // print_coor(x, y);
        // cout << "dir: " << dir << endl;
        switch(dir){
            case 'A':
                jump(plus_iter, minus_iter, &pplus, &pminus, x, y, m_minus, 1);
                break;
            case 'B':
                jump(minus_iter, plus_iter, &pminus, &pplus, y, x, m_plus, 1);
                break;
            case 'C':
                jump(minus_iter, plus_iter, &pminus, &pplus, y, x, m_plus, 0);
                break;
            case 'D':
                jump(plus_iter, minus_iter, &pplus, &pminus, x, y, m_minus, 0);
                break;
        }
        // cout << "land\n";
    }
    print_coor(x, y);
}
