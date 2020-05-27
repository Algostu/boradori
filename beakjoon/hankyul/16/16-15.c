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

// maximum sequence sum
int MSS(int N, int * arr, int * memo){
  int left, right, max;

  if(N==1) max = arr[N-1];
  else {
    left = arr[N-1];
    right = arr[N-1] + MSS(N-1, arr, memo);
    max = COMPARE(left, right);
  }

  memo[N-1] = max;

  return max;
}

void solve(int test_num){
  int N, arr[1000], memo[1000], max = -1000;
  scanf("%d", &N);

  for(int i = 0; i<N;i++){
    scanf("%d", arr+i);
    memo[i] = 0;
  }

  MSS(N, arr, memo);

  for(int i = 0; i<N;i++){
    if(max < memo[i]) max = memo[i];
  }

  printf("%d\n", max);
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
