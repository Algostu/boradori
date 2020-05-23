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

long long padoban(int N, long long * arr){
  long long p;
  if(arr[N] != -1) p = arr[N];
  else if(N <= 3) return 1;
  else{
    arr[N-3] = padoban(N-3, arr);
    arr[N-2] = padoban(N-2, arr);
    arr[N] = arr[N-3] + arr[N-2];
    p = arr[N];
  }
  return p;
}

void solve(int test_num){
  int i, n;
  long long arr[101];

  scanf("%d", &n);
  
  for(i=0;i<=n;i++){
    arr[i] = -1;
  }

  printf("%lld\n", padoban(n, arr));
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(i+1);
  }

  // solve(0);

	return 0;
}
