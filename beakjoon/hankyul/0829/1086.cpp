#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>

#define FIXED_VAL 100000000
#define FIXED_LEN 9

using namespace std;

string numbers[16];
int ans = 0;
int total = 0;

int recursive_modular(string a, int K, int fixedRem){
  if(a.length() <= FIXED_LEN){
    return stoi(a) % K;
  } else {
    int len = a.length();
    return (((recursive_modular(a.substr(0, len - FIXED_LEN), K, fixedRem) % K) * fixedRem) % K + stoi(a.substr(len-FIXED_LEN, FIXED_LEN)) % K) % K;
  }
}

string make_complete_str(int arr[], int n){
  string result;

  for (size_t i = 0; i < n; i++) {
    result += numbers[arr[i]];
  }
  //cout << result << endl;
  return result;
}

void perm(int arr[], int depth, int n, int K) {
  if (depth == n) {
    if (!recursive_modular(make_complete_str(arr, n), K, FIXED_VAL % K)){
      ans++;
    }
    total++;
    return;
  }

  for (int i = depth; i < n; i++) {
    swap(arr[i], arr[depth]);
    perm(arr, depth + 1, n, K);
    swap(arr[i], arr[depth]);
  }
}

int gcd(int a, int b){
  int r = a % b;
  if (r == 0) return b;
  else return gcd(b, r);
}

void solve(int test_num = 0){
  int N, K;
  int arr [15];
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> numbers[i];
    arr[i] = i;
  }
  cin >> K;
  perm(arr, 0, N, K);

  if(ans==0){
    cout << "0/1\n";
  } else if (ans == 1){
    cout << "1/1\n";
  } else{
    int div = gcd(total, ans);
    ans /= div; total /= div;
    cout << ans << "/" << total << "\n";
  }
}

int main(void){
  solve();
}
