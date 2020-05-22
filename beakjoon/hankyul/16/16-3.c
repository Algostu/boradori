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

// damn it
void solve(int test_num){
  int i, j, N, n, m, start, size;
  float ans = 0;
  float arr[100][1001];

  scanf("%d", &N);

  // memory explode
  // for(i=0;i<N+1;i++){
  //   if(i<=N/2){
  //     MALLOC(arr[i], sizeof(float) * (i+1));
  //   } else {
  //     j = (i-N/2) * 2 - (N&1); start = j; size = i+1 - start;
  //     MALLOC(arr[i], sizeof(float) * size);
  //     arr[i] -= j;
  //   }
  // }

  arr[1][0] = (float)1/15746;

  //debug
  // printf("arr[1][0] : %f\n", arr[0][0]);

  for(i=1;i<N+1;i++){
    if(i <= N/2) {j = 0; start = j; size = i+1 - start;}
    else {j = (i-N/2) * 2 - (N&1); start = j; size = i+1 - start;}

    for(j;j<i+1;j++){

      if(j-1 < 0) arr[i%99+1][j] = arr[i%99][j];
      else if (j > i-1)  arr[i%99+1][j] = arr[i%99][j-1];
      else arr[i%99+1][j] = arr[i%99][j-1] + arr[i%99][j];

      arr[i%99+1][j] -= floor(arr[i%99+1][j]);

      // debug
      // printf("%d_C_%d : %f\n", i, j, arr[1][j]);
    }

    if(i >= N/2 + (N&1)){
      ans += arr[i%99+1][(i-N/2) * 2 - (N&1)];
      ans -= floor(ans);
    }

    if((i+1)%99 == 0) memcpy(arr[0], arr[i%99+1], sizeof(float) * 1001);
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
