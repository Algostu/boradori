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

void mul(int (*arr1)[5], int (*arr2)[5], size_t N){
  int i, j, k, s;
  int arr3[5][5];
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      s = 0;
      for(k=0;k<N;k++){
        s += (((arr1[i][k]%1000) * (arr2[k][j]%1000))%1000);
      }
      arr3[i][j] = s % 1000;
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
  int N;
  long long B;
  int i, j, k;
  int arr1[5][5], arr2[5][5], memo[65][5][5];

  // input array1
  scanf("%d %lld", &N, &B);

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &arr2[i][j]);
      memo[1][i][j] = memo[0][i][j] = arr2[i][j];
      if(i==j) arr1[i][j] = 1;
      else arr1[i][j] = 0;
    }
  }

  // store memo
  for(i=1;i<64;i++){
    mul(memo[i], memo[i-1], N);
    for(j=0;j<N;j++){
      for(k=0;k<N;k++){
        memo[i+1][j][k] = memo[i][j][k];
      }
    }
  }

  // multiply
  // printf("=====================\n");
  for(i=0;i<64;i++){
    if((B >> i) & 1){
      mul(arr1, memo[i], N);
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%d ", arr1[i][j]);
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
