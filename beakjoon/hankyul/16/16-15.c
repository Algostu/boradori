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

int DP(int width, int max, int size, int * arr, int * memo){
  int result = 0, temp;

  for(int i = (width-1); i<size; i++){
    memo[i-(width-1)] += arr[i];
    if(max < memo[i-(width-1)]) max = memo[i - (width-1)];
  }
  // printf("width : %d size : %d max : %d\n", width, size, max);

  if(width == size) return max;
  else {
    temp = DP(width+1, max, size, arr, memo);
    return COMPARE(max, temp);
  }
}

void solve(int test_num){
  int N, arr[1000], memo[1000], max = -1000;
  scanf("%d", &N);

  for(int i = 0; i<N;i++){
    scanf("%d", arr+i);
    memo[i] = 0;
    if(max < arr[i]) max = arr[i];
  }

  printf("%d\n", DP(1, max, N, arr, memo));
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
