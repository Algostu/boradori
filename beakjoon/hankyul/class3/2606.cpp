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
  int N, M, r, c, ans=0, cur;
  char network[101][101];
  char computer[101] = {0};
  vector<int> convicted;

  for(int i=0; i<101;i++){
    for(int j=0; j<101; j++){
      network[i][j] = 0;
    }
  }

  cin >> N >> M;

  for(int i=0; i<M; i++){
    scanf("%d %d", &r, &c);
    network[r][c]=1;
    network[c][r]=1;
  }

  convicted.push_back(1);
  computer[1] = 1;
  ans = 0;

  while(!convicted.empty()){
    cur = convicted.back(); convicted.pop_back();
    for(int i=1; i<=N; i++){
      if(network[cur][i] && !computer[i]){
        convicted.push_back(i);
        computer[i]=1;
        ans++;
      }
    }
  }

  printf("%d\n", ans);
}

int main(void){
  solve();
}
