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

int magic(int X, int * memo){
  int m=X, temp;

  if(X==1) return 0;

  if(memo[X-1] != -1) m = memo[X-1];
  else {
    if (X % 3 == 0) { m = magic(X/3, memo); }
    if (X % 2 == 0) { temp = magic(X/2, memo); if(m > temp) m = temp;}
    temp = magic(X-1, memo); if(m > temp) m = temp;
    m+=1;
    memo[X-1] = m;
  }

  return m;
}

void solve(int test_num){
  int memo[1000];
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
    memo[i]=-1;
  }
  printf("%d\n", magic(N, memo));
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
