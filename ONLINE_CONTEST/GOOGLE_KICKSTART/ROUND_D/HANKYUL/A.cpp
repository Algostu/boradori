#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

void solve(int test_num = 0){
  int N;
  int ans=0;
  int cur, max=0, cur_prev, cur_fol, before_prev=-1, before_fol;
  cin >> N;

  for(int i=0; i<N; i++){
    scanf("%d", &cur);
    cur_prev=-1;
    if(i==0 || cur > max){
      cur_prev = cur;
      max = cur;
    }
    if(before_prev > cur){
      ans++;
    }
    if(i==N-1 && cur_prev != -1){
      ans++;
    }
    before_prev = cur_prev;
  }

  printf("Case #%d: %d\n", test_num, ans);
}

int main(void){
  int T;
  cin >> T;
  for(int i = 0; i<T; i++){
      solve(i+1);
  }
}
