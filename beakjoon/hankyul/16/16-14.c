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

int LCS(int N, int M, char * A, char * B, int (*memo)[1001]){
  int max = 0;
  int left, right;
  // printf("N : %d M : %d \n", N, M);
  if(memo[N][M] != -1) return memo[N][M];

  else if (N == 0 || M == 0) max = 0;

  else if (A[N-1] == B[M-1]) max = 1 + LCS(N-1, M-1, A, B, memo);

  else {
    left = LCS(N-1, M, A, B, memo);
    right = LCS(N, M-1, A, B, memo);
    max = COMPARE(left, right);
  }

  memo[N][M] = max;

  return max;
}

void solve(int test_num){
  int memo[101][1001];
  char A[1001], B[1001];

  scanf("%s", A);
  scanf("%s", B);

  for(int i=0; i<=strlen(A); i++){
    for(int j=0; j<=strlen(B); j++){
      memo[i][j] = -1;
    }
  }

  printf("%d\n", LCS(strlen(A), strlen(B), A, B, memo));

  // for(int i=0; i<strlen(A); i++){
  //   for(int j=0; j<strlen(B); j++){
  //     printf("%4d ", memo[i][j]);
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
