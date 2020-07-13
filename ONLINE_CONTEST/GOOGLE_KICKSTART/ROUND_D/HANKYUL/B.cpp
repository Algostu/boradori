#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int DP(int fix, int before, int idx, int * human, int (*memo)[4], int len){
  int ans = 1000000;
  if(memo[idx][before] != -1){
    ans = memo[idx][before];
  }
  else if(idx==len){
    ans = fix;
  }
  else if(human[idx-1] < human[idx]){
    if(before != 3){
      for(int i=before+1; i<4; i++){
        int temp = DP(fix, i, idx+1, human, memo, len);
        if(ans > temp) ans = temp;
        if(ans == 0){
          return ans;
        }
      }
    } else {
      for(int i=0; i<4; i++){
        int temp = DP(fix+1, i, idx+1, human, memo, len);
        if(ans > temp) ans = temp;
        if(ans == 0){
          return ans;
        }
      }
    }

  }
  else if(human[idx-1] == human[idx]){
    ans = DP(fix, before, idx+1, human, memo, len);
    if(ans == 0){
      return ans;
    }
  }
  else if(human[idx-1] > human[idx]){
    if(before != 0){
      for(int i=before-1; i>=0; i--){
        int temp = DP(fix, i, idx+1, human, memo, len);
        if(ans > temp) ans = temp;
        if(ans == 0){
          return ans;
        }
      }
    }
    else {
      for(int i=0; i<4; i++){
        int temp = DP(fix+1, i, idx+1, human, memo, len);
        if(ans > temp) ans = temp;
        if(ans == 0){
          return ans;
        }
      }
    }
  }
  memo[idx][idx];
  return ans;
}

void solve(int test_num = 0){
  int N, ans = 10000;
  int human[10002];
  int memo[10002][4];
  cin >> N;

  for(int i=0; i<10003; i++){
    for(int j=0; j<4; j++){
      memo[i][j] = -1;
    }
  }

  for(int i=0; i<N; i++){
    scanf("%d", human+i);
  }

  for(int i=0; i<4; i++){
    int temp = DP(0, i, 1, human, memo, N);
    if(temp < ans){
      ans = temp;
    }
    if(ans == 0){
      break;
    }
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
