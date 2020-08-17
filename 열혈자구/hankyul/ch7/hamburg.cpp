#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <random>
#include <cstring>
#include <cmath>

using namespace std;

#define CUS_COME_TERM 15

enum {CHE_BUR, BUL_BUR, DUB_BUR};

enum {CHE_TERM = 12, BUL_TERM = 15, DUB_TERM = 24};

void solve(int test_num = 0){
  int makeProc = 0;
  int cheOrder = 0, bulOrder = 0, dubOrder = 0;

  random_device rd;

  mt19937 gen(rd());

  uniform_int_distribution<int> dis(0, 3);

  queue<int> que;

  for (size_t sec = 0; sec < 3600; sec++) {
    if(sec % CUS_COME_TERM == 0){
      switch(dis(gen)){
        case CHE_BUR:
          que.push(CHE_TERM);
          cheOrder+=1;
          break;

        case BUL_BUR:
          que.push(BUL_TERM);
          bulOrder+=1;
          break;

        case DUB_BUR:
          que.push(DUB_TERM);
          dubOrder+=1;
          break;
      }
    }

    if(makeProc <= 0 && !que.empty()){
      makeProc = que.front(); que.pop();
    }

    makeProc--;
  }


  printf(" - cheese burger: %d\n", cheOrder);
  printf(" - bulgogi burger: %d\n", bulOrder);
  printf(" - double burger: %d\n", dubOrder);

}

int main(void){
  solve();
}
