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

void fibo(int n, long long (* arr)[2], int* index, long long * zero , long long * one){
  if(n == 0) {arr[0][0] = 1; arr[0][1] = 0; *zero = arr[n][0]; *one = arr[n][1];}
  else if(n==1){arr[1][0] = 0; arr[1][1] = 1; *zero = arr[n][0]; *one = arr[n][1];}
  else if (n <= *index){
    *zero = arr[n][0]; *one = arr[n][1];
  } else{
    fibo(n-2, arr, index, zero, one);
    arr[n-2][0] = *zero;
    arr[n-2][1] = *one;
    if(*index < n-2) *index = n-2;
    fibo(n-1, arr, index, zero, one);
    arr[n-1][0] = *zero;
    arr[n-1][1] = *one;
    arr[n][0] = arr[n-2][0] + arr[n-1][0];
    arr[n][1] = arr[n-2][1] + arr[n-1][1];
    if(*index < n) *index = n;
    *zero = arr[n][0]; *one = arr[n][1];
    return;
  }
}

void solve(int test_num){
  int N, n=0;
  long long arr[41][2], zero=0, one=0;
  scanf("%d", &N);

  fibo(N, arr, &n, &zero, &one);
  printf("%lld %lld\n", arr[N][0], arr[N][1]);
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
