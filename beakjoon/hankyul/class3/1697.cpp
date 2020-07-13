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
  int N, K, cur_w, cur_a;
  char visited[100001] = {0};
  queue<int> where, ans;
  cin >> N >> K;

  // case 1
  if((K - N) <= 1){
    printf("%d\n", abs(K-N));
    return;
  }

  // case 2
  where.push(N);
  ans.push(0);
  visited[N] = 1;
  while(1){
    cur_w = where.front(); cur_a = ans.front();
    where.pop(); ans.pop();

    if(cur_w == K){
      printf("%d\n", cur_a);
      return;
    } else if (cur_w-1 == K || cur_w+1 == K || cur_w * 2 == K){
      printf("%d\n", cur_a+1);
      return;
    }

    if(cur_w > 0 && !visited[cur_w-1]){
        where.push(cur_w-1); ans.push(cur_a+1); visited[cur_w-1]=1;
    }

    if(cur_w < K && !visited[cur_w+1]){
      where.push(cur_w+1); ans.push(cur_a+1); visited[cur_w+1]=1;
    }

    if(100000 >= cur_w *2 && K > 1.5 * cur_w && !visited[cur_w*2]){
        where.push(cur_w*2); ans.push(cur_a+1); visited[cur_w*2]=1;
    }

  }

}

int main(void){
  solve();
}
