#include <bits/stdc++.h>

using namespace std;

int main(void){
  long long n, k;
  cin >> n >> k;
  long long l = 1;
  long long r = k;
  long long ans = 1;
  while(l<=r){
    long long c = 0;
    long long m = (l+r)/2;
    for(int i=1; i<=n; i++) c += min(n, m/i);
    if(c < k) l = m+1;
    else {
      ans = m;
      r = m-1;
    }
  }
  cout << ans << "\n";
}