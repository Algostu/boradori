#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

#define CALLOC(X, Y, Z) \
if(((X) = calloc((Y), (Z)))==NULL){\
  fprintf(stderr, "callc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int i, j, k, k_1, N, n, m, start, size;
  float ans = 0;
  float arr[2][100001]={0};

  scanf("%d", &N);

  arr[0][0] = (float)1/15746;

  //debug
  // printf("arr[0][0] : %f\n", arr[0][0]);

  for(i=1;i<N+1;i++){
    if(i <= N/2) {j = 0; start = j; size = i+1 - start;}
    else {j = (i-N/2) * 2 - (N&1); start = j; size = i+1 - start;}

    if(i % 2 == 1) {k_1 = 0; k = 1;}
    else {k_1 = 1; k = 0;}

    for(j;j<i+1;j++){

      if(j-1 < 0) arr[k][j] = arr[k_1][j];
      else if (j > i-1)  arr[k][j] = arr[k_1][j-1];
      else arr[k][j] = arr[k_1][j-1] + arr[k_1][j];

      arr[k][j] -= floor(arr[k][j]);

      // debug
      // printf("%d_C_%d : %f\n", i, j, arr[1][j]);
    }

    if(i >= N/2 + (N&1)){
      ans += arr[k][(i-N/2) * 2 - (N&1)];
      ans -= floor(ans);
    }

  }

  printf("%.0f\n", ans*15746);
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve();
  // }

  solve(0);

	return 0;
}
