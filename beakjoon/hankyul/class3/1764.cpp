#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool operator>(const string & a, const string & b){
  if(a[0] > b[0]) return 1;
  else return 0;
}

bool operator<(const string & a, const string & b){
  if(a[0] < b[0]) return 1;
  else return 0;
}

void solve(int test_num = 0){
  int N, M;
  char input[30];
  vector<string> ans;
  map<string,int> first_input;
  cin >> N >> M;

  for(int i=0; i<N; i++){
    scanf("%s", input);
    first_input[input];
  }

  for(int i=0; i<M; i++){
    scanf("%s", input);
    if(first_input.find(input)!=first_input.end()){
      ans.push_back(input);
    }
  }

  sort(ans.begin(), ans.end());

  printf("%d\n", ans.size());

  for(int i=0; i<ans.size(); i++){
    printf("%s\n", ans[i].c_str());
  }

}

int main(void){
  solve();
}
