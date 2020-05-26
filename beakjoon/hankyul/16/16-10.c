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

int drink(int i, int c, int n, int * juice, int (*memo)[3]){
  int d = 0, d_1 = juice[i], d_2 = juice[i], d_3 = juice[i], big;

  if(i+1 == n) return juice[i];

  if(c != 1) {
    if(memo[i][0]!=-1) d_1 = memo[i][0];
    else {
      d_1 += drink(i+1, c+1, n, juice, memo);
      memo[i][0] = d_1;
    }
  }
  if(i+2 != n) {
    if(memo[i][1]!=-1) d_2 = memo[i][1];
    else{
      d_2 += drink(i+2, 0, n, juice, memo);
      memo[i][1] = d_2;
    }
  }
  if(i+3 != n){
    if(memo[i][2]!=-1) d_3 = memo[i][2];
    else{
      d_3 += drink(i+3, 0, n, juice, memo);
      memo[i][2] = d_3;
    }
  }

  big = COMPARE(d_1, d_2);

  return COMPARE(big, d_3);
}

void solve(int test_num){
  int N, i, j, ans=0, juice[10000], memo[10000][3];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", juice+i);
    for(j=0;j<3;j++){
      memo[i][j] = -1;
    }
  }

  if(N==1) { printf("%d\n", juice[0]); return; }
  else if(N==2) { printf("%d\n", juice[0] + juice[1]); return; }

  printf("%d\n", COMPARE(drink(0, 0, N, juice, memo), drink(1, 0, N, juice, memo)));

  // debug
  for(i=0;i<N;i++){
    for(j=0;j<2;j++){
      printf("%4d", memo[i][j]);
    }
    printf("\n");
  }

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
