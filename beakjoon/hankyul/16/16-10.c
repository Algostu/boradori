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

int A(int N, int C, int * drink, int (*memo)[3]){
  int max, left, right;

  if (memo[N][C] != -1) return memo[N][C];

  if (N <= 0) max = 0;
  else if (C == 2) max = A(N-1, 0, drink, memo);
  else {
    left = drink[N-1] + A(N-1, C+1, drink, memo);
    right = A(N-1, 0, drink, memo);
    max = COMPARE(left, right);
  }

  memo[N][C] = max;

  return max;
}

void solve(int test_num){
  int N, i, j, ans=0, juice[10000], memo[10001][3];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", juice+i);
  }

  for(i=0; i<=N; i++){
    for(j=0;j<3;j++){
      memo[i][j] = -1;
    }
  }

  printf("%d\n", A(N, 0, juice, memo));

  // debug
  // for(i=0;i<=N;i++){
  //   for(j=1;j<=2;j++){
  //     printf("%4d", memo[i][j]);
  //   }
  //   printf("\n");
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
