#include <bits/stdc++.h>

using namespace std;

void all_comb(int n, int mask, int C, vector<int> arr, vector<int> & result){
    for (size_t i = 0; i < mask; i++)
    {
        long long sum = 0;
        for (size_t j = 0; j < n; j++)
        {
            sum += (i & (1 << j)) ? arr[j] : 0;
            // if((i & (1 << j))){
            //     cout << arr[j] << " ";
            // }
        }
        // cout << endl;
        if(sum <= C) result.push_back(sum);
    }
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, C;
    vector<int> a, b, c, d;
    cin >> N >> C;
    for (size_t i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if(i<N/2) a.push_back(tmp);
        else b.push_back(tmp);
    }
    int a_n = a.size(), b_n = b.size();
    int a_pow = pow(2, a_n), b_pow = pow(2, b_n);
    all_comb(a_n, a_pow, C, a, c);
    all_comb(b_n, b_pow, C, b, d);

    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    long long c_idx, d_idx, cnt, c_sz;
    c_idx = cnt = 0, d_idx = d.size()-1, c_sz = c.size();

    while(c_idx!=c_sz){
        int sum = c[c_idx] + d[d_idx];
        if(sum <= C) cnt += (d_idx+1);
        if(sum <= C or d_idx == 0) c_idx++;
        else d_idx--;
    }

    cout << cnt << endl;

    return 0;
}