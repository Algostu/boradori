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

typedef struct __line{
  int from;
  int to;
} line;

int comp(const void * a, const void * b){
  return (*((line*)a)).from - (*((line*) b)).from;
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
  int min, min_val, N, sub_line, arr[100], memo[100];
  line lines[100];

  scanf("%d", &N);

  for(int i=0;i<N;i++){
    scanf("%d %d", &lines[i].from, &lines[i].to);
    memo[i] = -1;
  }

  qsort(lines, N, sizeof(line), comp);

  for(int i=0; i<N;i++){
    arr[i] = lines[i].to;
  }

  min = arr[0];
  min_val = 0;

  for(int i=0;i<N;i++){
    if(arr[i]<=min){
      if(min_val < DP(i, N, arr, memo)) min_val = DP(i, N, arr, memo);
      min = arr[i];
    }
  }

  printf("%d\n", N - min_val);
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
