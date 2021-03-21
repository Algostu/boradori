#include <bits/stdc++.h>

using namespace std;


int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    int i=1;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        string arr;
        cin >> arr;
        int diff_num = 0;
        for(int i=0; i<(N/2); i++){
            if(arr[i] != arr[N-i-1]) diff_num++;
        }
        cout << "Case #" << (i++) << ": " << abs(K-diff_num) << endl;
    }
    return 0;
}