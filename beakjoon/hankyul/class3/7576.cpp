#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dirs[4][2] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void solve(int test_num = 0){
  int N, M, r, c, temp, kid=0, all=0, ans=0;
  char maps[1002][1002];
  queue<tuple<int,int>> keys;
  cin >> M >> N;

  for(int i=0; i<1002; i++){
    for(int j=0; j<1002; j++){
      maps[i][j] = -1;
    }
  }

  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      scanf("%d", &temp);
      maps[i][j] = temp;
      if(maps[i][j]==1 || maps[i][j]==0){
        if(maps[i][j]==1){
          keys.push(make_tuple(i, j));
          maps[i][j] = -1;
        }
        if(maps[i][j]==0){
          all++;
        }
      }
    }
  }

  while(!keys.empty()){
    int len = keys.size();
    for(int i=0; i<len; i++){
      tuple<int, int> cur = keys.front(); keys.pop();
      for(int j=0; j<4; j++){
        int r = get<0>(cur) + dirs[j][0], c = get<1>(cur) + dirs[j][1];
        if(maps[r][c]==0) { maps[r][c]=-1; keys.push(make_tuple(r, c)); kid++;}
      }
    }
    // cout << ans << "===============================" << endl;
    // for(int i=0; i<=N+1; i++){
    //   for(int j=0; j<=M+1; j++){
    //     printf("%d ", maps[i][j]);
    //   }
    //   cout << endl;
    // }
    ans++;
  }
  // printf("kid : %d all : %d ans : %d\n", kid, all, ans);
  if(kid == all) cout << ans-1 << endl;
  else cout << -1 << endl;

}

int main(void){
  solve();
}
