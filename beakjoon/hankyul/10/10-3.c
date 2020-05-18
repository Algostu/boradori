#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int* Eratos(int n){
  int i,j;
  int* arr;
  MALLOC(arr, sizeof(int) * n+1);
  arr[1] = 0;

  for(i=2;i<=n;i++){
    arr[i] = 1;
  }

  for(i=2;i*i<=n;i++){
    if(arr[i])
    for(j=i*i;j<=n;j+=i){
      arr[j]=0;
    }
  }
  return arr;
}

void solve(int test_num){
  int M, N, i, *primeArray;
  scanf("%d %d", &M, &N);
  primeArray = Eratos(N);
  for(i=M;i<=N;i++){
    if(primeArray[i]){
      printf("%d\n", i);
    }
  }
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(0);
  // }

  solve(0);
	return 0;
}
