#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

void mul(long long (*arr1)[5], long long (*arr2)[5], size_t N){
  int i, j, k, s;
  int arr3[5][5];
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      s = 0;
      for(k=0;k<N;k++){
        s += (((arr1[i][k]%1000000) * (arr2[k][j]%1000000))%1000000);
      }
      arr3[i][j] = s % 1000000;
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      arr1[i][j] = arr3[i][j];
      // printf("%d ", arr1[i][j]);
    }
    // printf("\n");
  }
  // printf("\n");
}
void solve(int test_num){
  long long N;
  int i, j, k;
  long long arr1[5][5], arr2[5][5], memo[65][5][5];

  // input N
  scanf("%lld", &N);

  // exception
  if(N==0 || N==1) { printf("%lld\n", N); return; }

  memo[0][0][0] = memo[1][0][0] = 1;
  memo[0][0][1] = memo[1][0][1] = 1;
  memo[0][1][0] = memo[1][1][0] = 1;
  memo[0][1][1] = memo[1][1][1] = 0;
  arr1[0][0] = 1; arr1[0][1] = 0; arr1[1][0] = 0; arr1[1][1] = 1;

  // store memo
  for(i=1;i<64;i++){
    mul(memo[i], memo[i-1], 2);
    for(j=0;j<2;j++){
      for(k=0;k<2;k++){
        memo[i+1][j][k] = memo[i][j][k];
      }
    }
  }

  // multiply
  // printf("=====================\n");
  for(i=0;i<64;i++){
    if((N-1 >> i) & 1){
      mul(arr1, memo[i], 2);
    }
  }

  printf("%lld\n", arr1[0][0]);


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
