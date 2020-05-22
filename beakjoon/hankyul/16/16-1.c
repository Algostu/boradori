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

long long fibo(int n, long long * arr, int* index){
  if(n==0 || n == 1){
    arr[n] = n;
    return arr[n];
  }
  if (n <= *index){
    return arr[n];
  } else{
    arr[n-2] = fibo(n-2, arr, index);
    if(*index < n-2) *index = n-2;
    arr[n-1] = fibo(n-1, arr, index);
    if(*index < n-1) *index = n-1;
    arr[n] = arr[n-1] + arr[n-2];
    if(*index < n) *index = n;
    return arr[n];
  }
}

void solve(int test_num){
  int N, n;
  long long ans;
  long long arr[91];

  scanf("%d", &N);

  n = 0;

  ans = fibo(N, arr, &n);
  printf("%lld\n", ans);
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
