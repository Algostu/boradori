#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

void rotate(int x, int & state){
  state = (state + x) % 4;
  cout << state;
  if(x==1 || x==-3){

  }
}

void solve(int test_num = 0){
  int N;

  cin >> N;

  rotate(0, N);
}

int main(void){
  solve();
}
