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

int combi(int N, int K, int (*memo)[101]){
  int ans = 0;
  if(memo[N][K] != -1) return memo[N][K];
  else if(K==0 || K==N || N==1) ans = 1;
  else ans = (combi(N-1, K-1, memo)%10007 + combi(N-1, K, memo)%10007)%10007;
  memo[N][K] = ans;
  return ans;
}

void solve(int test_num){
  int N, K, memo[1001][101];

  scanf("%d %d", &N, &K);

  for(int i = 0; i<=N; i++){
    for(int j = 0; j<=N; j++){
      memo[i][j] = -1;
    }
  }

  printf("%d\n", combi(N, K, memo));
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
