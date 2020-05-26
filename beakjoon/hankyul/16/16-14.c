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

int LCS(int a, int b, int N, int M, char * A, char * B, int (*memo)[1000]){
  int max = 0;

  for(int i = a; i<N; i++){
    for(int j = b; j<M; j++){
      if (memo[i][j] != -1 && max < memo[i][j]) max = memo[i][j];
      else if(A[i] == B[j]) {memo[i][j] = 1 + LCS(i+1, j+1, N, M, A, B, memo); if(max < memo[i][j]) max = memo[i][j]; break;}
    }
  }

  return max;
}

void solve(int test_num){
  int memo[100][1000];
  char A[1001], B[1001];

  scanf("%s", A);
  scanf("%s", B);

  for(int i=0; i<strlen(A); i++){
    for(int j=0; j<strlen(B); j++){
      memo[i][j] = -1;
    }
  }

  printf("%d\n", LCS(0, 0, strlen(A), strlen(B), A, B, memo));

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
