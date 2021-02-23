#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> prime;
    bool isPrime[N+1];
    memset(isPrime, true, N+1);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=N; i++)
        if(isPrime[i])
            for(int j=i*i; j<=N; j+=i)
                isPrime[j] = false;
    for(int i=2; i<=N; i++)
        if(isPrime[i])
            prime.push_back(i);
    int s, e, cnt, ans;
    s = e = cnt = 0, ans = 0;
    int size = prime.size();
    while(s<size){
        if(ans>=N or e==size) { ans-=prime[s]; s++; }
        else { ans+=prime[e]; e++; }
        if(ans == N) cnt++;
    }
    cout << cnt << endl    ;
    return 0;
}
