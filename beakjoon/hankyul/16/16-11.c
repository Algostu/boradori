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

int DP(int n, int size, int *arr, int *memo){
  int max = 1;
  if(memo[n] != -1) return memo[n];

  if(n+1 == size){
    return 1;
  }

  for(int i=n+1;i<size;i++){
    if(arr[n] < arr[i]){
      if(memo[i] != -1 && memo[i]+1 > max) max = 1 + memo[i];
      else if(DP(i, size, arr, memo)+1 > max) max = 1 + DP(i, size, arr, memo);
    }
  }
  memo[n] = max;
  return max;

}


void solve(int test_num){
  int min, min_val, N, A[1000], sub_len[1000];

  scanf("%d", &N);

  for(int i=0;i<N;i++){
    scanf("%d", A+i);
    sub_len[i] = -1;
  }

  min = A[0];
  min_val = 0;

  for(int i=0;i<N;i++){
    if(A[i]<=min){
      if(min_val < DP(i, N, A, sub_len)) min_val = DP(i, N, A, sub_len);
      min = A[i];
    }
  }

  printf("%d\n", min_val);

  // for(int i = 0; i<N; i++){
  //   printf("%d ", sub_len[i]);
  // }
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
