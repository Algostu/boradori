#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX_LONG 10000000

using namespace std;

long long diff(const long long height, int N, vector<long long> Yk, vector<long long> Dk){
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += abs(Yk[i] - (height + abs(N/2 - i)));
    sum += abs(Dk[i] - (height + abs(N/2 - i)));
  }

  return sum;
}

void solve(int test_num = 0){
  int N;
  vector<long long> Yk, Dk;
  cin >> N;
  long long high = 0, low = MAX_LONG;

  for (size_t i = 0; i < N; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    Yk.push_back(tmp);

    if(high < tmp){
      high = tmp;
    }
    if(low > tmp){
      low = tmp;
    }
  }

  for (size_t i = 0; i < N; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    Dk.push_back(tmp);

    if(high < tmp){
      high = tmp;
    }
    if(low > tmp){
      low = tmp;
    }
  }


  while(low < high - 1){
    long long height = (high + low) / 2;

    if(diff(height, N, Yk, Dk) <= diff(height-1, N, Yk, Dk)){
      low = height;
    } else{
      high = height;
    }
  }

  printf("%lld\n", diff(low, N, Yk, Dk));
}

int main(void){
  solve();
}
