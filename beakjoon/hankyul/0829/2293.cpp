#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX_VALUE 10001
using namespace std;

array<int, MAX_VALUE> memo{};

void solve(int test_num = 0){
  int N, K;
  int coin;
  cin >> N >> K;
  memo[0] = 1;
  for (size_t i = 0; i < N; i++) {
    cin >> coin;
    for (size_t j = coin; j <= K; j++) {
      memo[j] += memo[j - coin];
    }
  }
  cout << memo[K];
}

int main(void){
  solve();
}
