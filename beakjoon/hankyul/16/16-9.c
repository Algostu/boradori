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

int stair_num(int i, int j, int n, int (*memo)[10]){
  int s = 0, s_1 = 0, s_2 = 0;

  if(memo[j][i]!=-1) return memo[j][i];

  if(j+1 >= n) return 1;

  if(i+1<10) s_1 = stair_num(i+1, j+1, n, memo);
  if(i-1>-1) s_2 = stair_num(i-1, j+1, n, memo);

  s = (s_1 % 1000000000 + s_2 % 1000000000) % 1000000000;

  memo[j][i] = s;

  return s;
}

void solve(int test_num){
  int N, i, j, ans=0, memo[100][10];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    for(j=0;j<10;j++){
      memo[i][j] = -1;
    }
  }

  if(N==1) { printf("9\n"); return; }
  // else if(N==2) { printf("17\n"); return; }

  for(i=1;i<10;i++){
    ans = (ans % 1000000000 + stair_num(i, 0, N, memo) % 1000000000) % 1000000000;
  }

  //debug
  // for(i=0;i<N;i++){
  //   for(j=0;j<10;j++){
  //     printf("%4d", memo[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%d\n", ans);
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
