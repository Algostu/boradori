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

typedef struct __object{
  int w;
  int v;
} object;

int KS(int N, int K, object * objs, int (*memo)[1001]){
  int left, right, max = 0;
  if(memo[N][K] != -1) max = memo[N][K];
  else if(N==0 || K==0) max = 0;
  else if(objs[N-1].w > K) max = KS(N-1, K, objs, memo);
  else {
    left = objs[N-1].v + KS(N-1, K-objs[N-1].w, objs, memo);
    right = KS(N-1, K, objs, memo);
    max = COMPARE(left, right);
  }
  memo[N][K] = max;
  return max;
}

void solve(int test_num){
  int N, K;
  int memo[101][1001];
  object objs[100];
  object bag = {0, 0};

  scanf("%d %d", &N, &K);

  for(int i = 0; i<N;i++){
    scanf("%d %d", &objs[i].w, &objs[i].v);
  }

  for(int i = 0; i<101;i++){
    for(int j = 0; j<1001; j++){
      memo[i][j] = -1;
    }
  }

  printf("%d\n", KS(N, K, objs, memo));
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
