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

void solve(int test_num){
  int N, M, K, s;
  int i, j, k;
  int arr1[100][100], arr2[100][100], arr3[100][100];

  // input array1
  scanf("%d %d", &N, &M);

  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d", &arr1[i][j]);
    }
  }

  // input array2
  scanf("%d %d", &M, &K);

  for(i=0;i<M;i++){
    for(j=0;j<K;j++){
      scanf("%d", &arr2[i][j]);
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<K;j++){
      s = 0;
      for(k=0;k<M;k++){
        s += arr1[i][k] * arr2[k][j];
      }
      printf("%d ", s);
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
