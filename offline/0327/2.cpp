#include <bits/stdc++.h>

using namespace std;

vector<int> w(31), rw, lw;

void comb(int idx, int max_idx, long long sum, long long max_sum, vector<int> & result){
    if(idx==max_idx){
        if(sum<=max_sum)
            result.push_back(sum);
        return;
    }
    comb(idx+1, max_idx, sum+w[idx], max_sum, result);
    comb(idx+1, max_idx, sum, max_sum, result);
}

int get_cnt(vector<int> & arr, int limit){
    return upper_bound(arr.begin(), arr.end(), limit) - arr.begin();
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++) cin >> w[i];

    comb(0, N/2, 0, C, lw);
    comb(N/2, N, 0, C, rw);

    sort(rw.begin(), rw.end());
    sort(lw.begin(), lw.end());

    int cnt = 0;
    for(auto & it : lw){
        cnt += get_cnt(rw, C-it);
    }

    cout << cnt;
    return 0;
}