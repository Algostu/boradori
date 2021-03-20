#include <bits/stdc++.h>

using namespace std;

struct movie{
    float pref;
    char type;
    int row;
    int col;
};

struct less_than_key{
    bool operator() (const movie & a, const movie & b){
        return a.pref != b.pref ? a.pref > b.pref : 
        (a.row != b.row ? a.row < b.row : 
        a.col < b.col);
    }
};

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    vector<movie> O, Y;
    map<char, float> pref;
    char types[5] = {'A', 'B', 'C', 'D', 'E'};
    int N, M;
    for(int i=0; i<5; i++){
        float tmp;
        cin >> tmp;
        pref[types[i]] = tmp;
    }
    cin >> N >> M;
    vector<string> h, t;
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(h[i][j] == 'Y'){
                Y.push_back({pref[t[i][j]], t[i][j], i, j});
            } else if (h[i][j] == 'O'){
                O.push_back({pref[t[i][j]], t[i][j], i, j});
            }
        }
    }
    sort(O.begin(), O.end(), less_than_key());
    sort(Y.begin(), Y.end(), less_than_key());
    for(auto & a : Y){
        cout << a.type << " " << fixed << setprecision(1) << a.pref << " " << a.row << " " <<  a.col << endl;
    }

    for(auto & a : O){
        cout << a.type << " " << fixed << setprecision(1) << a.pref << " " << a.row << " " <<  a.col << endl;
    }

    return 0;
}