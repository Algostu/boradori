#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int getPriority(int op){
  if (op == '(' || op == ')') return -1;
  else if(op == '+' || op == '-') return 0;
  else if (op == '*' || op == '/') return 1;
  else return 2;
}

int calc(int op, int a, int b){
  if (op == '+') return a + b;
  else if (op == '-') return a - b;
  else if (op == '*') return (a) * (b);
  else return (a) / (b);

}

void solve(int test_num = 0){
  int N;
  string input;
  stack<char> ops;
  vector<char> output;
  cin >> input;

  for (size_t i = 0; i < input.size(); i++) {
    int pri = getPriority(input[i]);
    if(pri == 2) { output.push_back(input[i]); continue; }
    if(input[i] == '(') { ops.push(input[i]); continue; }

    while(!ops.empty()){
      if (getPriority(ops.top()) >= pri) {
        if(ops.top() != '(')
          output.push_back(ops.top());
        ops.pop();
      }
      else
        break;
    }

    if(input[i] != ')')
      ops.push(input[i]);
  }

  while(!ops.empty()){
    output.push_back(ops.top());
    ops.pop();
  }

  for (size_t i = 0; i < output.size(); i++) {
    int pri = getPriority(output[i]);
    if(pri == 2) { ops.push(output[i]-'0');}
    else {
      int op = output[i];
      int ops1 = ops.top(); ops.pop();
      int ops2 = ops.top(); ops.pop();
      ops.push(calc(op, ops2, ops1));
    }
  }
  printf("%d\n", ops.top());


}

int main(void){
  solve();
}
