#include <bits/stdc++.h>

using namespace std;

int time_to_int(string time){
    int h = atoi(time.substr(0, 2).c_str());
    int m = atoi(time.substr(3, 2).c_str());
    int s = atoi(time.substr(6, 2).c_str());

    return (h * 3600) + m * 60 + s;
}

int time_to_int2(string time){
    int m = atoi(time.substr(0, 2).c_str());
    int s = atoi(time.substr(3, 2).c_str());

    return m * 60 + s;
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N; string time;
    cin >> N >> time;
    int limit = time_to_int(time);
    vector<int> playlist;
    for (size_t i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        int tmp2 = time_to_int2(tmp);
        playlist.push_back(tmp2);
    }

    int s, e, cnt, sum, starting;
    s = e = cnt = sum = 0;

    while(s < N){
        if(sum >= limit or e == N) {
            sum -= playlist[s];
            s++;
        }
        else {
            sum += playlist[e]; e++;
        }
        if (sum<=limit){
            int tmp = e-s+ (e!=N and sum<limit ? 1 : 0);
            if(cnt < tmp){
                cnt = tmp;
                starting = s+1;
            }
        }
    }
    cout << cnt << " " << starting << endl;
    return 0;
}