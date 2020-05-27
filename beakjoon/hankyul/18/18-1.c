#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int N, K, max = 0, max_index = 0, num = 0, ans = 0;
  int coins[10];
  scanf("%d %d", &N, &K);

  for(int i = 0; i < N; i++){
    scanf("%d", coins+i);
  }

  for(int i=N-1;i>=0;i--){
    if(K % coins[i] == 0){
      max = coins[i];
      max_index = i;
      num = K / coins[i];
      break;
    }
  }

  for(int i=max_index;i<N;i++){
    coins[i] /= max;
  }

  int i = N-1;

  while(num != 0){
    if(coins[i] > num) { i--; continue; }
    ans += (num / coins[i]);
    num = num % coins[i];
  }

  printf("%d", ans);
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(i+1);
  // }

  solve(0);

	return 0;
}
