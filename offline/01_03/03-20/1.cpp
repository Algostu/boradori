#include <bits/stdc++.h>

using namespace std;

struct time_pair{
    string a;
    string b;
};

bool operator<(const string & a, const string & b){
    int h_a = atoi(a.substr(0, 2).c_str());
    int h_b = atoi(b.substr(0, 2).c_str());
    int m_a = atoi(a.substr(3, 2).c_str());
    int m_b = atoi(b.substr(3, 2).c_str());
    if (h_a == h_b){
        return m_a < m_b;
    } else {
        return h_a < h_b;
    }
}

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<time_pair> time_arr;
    for(int i=0; i<N; i++) { 
        string tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        time_arr.push_back({tmp1, tmp3}); 
    }
    string a = "00:00";
    string b = "23:59";
    for(int i=0; i<N; i++){
        if(time_arr[i].b < a or b < time_arr[i].a) {
            cout << "-1" << endl;
            return 0;
        } else {
            a = time_arr[i].a < a ? a : time_arr[i].a;
            b = time_arr[i].b < b ? time_arr[i].b : b;
        }
    }
    cout << a << " ~ " << b << endl;
    return 0;
}