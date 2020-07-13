#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int convert_to_digit(char * str){
  int ans=0, len = strlen(str);
  for(int i = 0; i<len; i++){
    if(str[len-(i+1)] <='9' && str[len-(i+1)] >= '0'){
      ans += (str[len-(i+1)]-'0') * pow(10, i);
    } else {
      return 0;
    }
  }
  return ans;
}

void solve(int test_num=0){
  int N, M, index;
  map<string, int> str_to_int;
  vector<string> int_to_str;
  char input[30];

  cin >> N >> M;

  for(int i =0 ;i<N;i++){
    scanf("%s", input);
    str_to_int[input] = i+1;
    int_to_str.push_back(input);
  }

  for(int i = 0; i<M; i++){
    scanf("%s", input);
    index = convert_to_digit(input);
    if(index==0){
      printf("%d\n", str_to_int[input]);
    } else{
      printf("%s\n", int_to_str[index-1].c_str());
    }
  }
}

int main(void){
  solve();
}
