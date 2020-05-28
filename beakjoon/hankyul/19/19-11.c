#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) < (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

long long zero_num(int n, long long base){
  int multi = base;
  long long ans = 0;
  int i=1;
  n -= (n%base);
  // printf("\nN : %d =================\n", n);
  while(base <= n){
    ans += (n/base);
    // printf("[%d] ans : %lld base : %d\n", i++, ans, base);
    base *= multi;
  }

  return ans;
}
void solve(int test_num){
  int i, j, N, K, temp, temp2;
  long long five, two;

  scanf("%d %d", &N, &K);

  if(N/2 < K) K = N-K;

  if(N==K || K==0) { printf("0\n"); return; }

  // five = zero_num(N, 0, 5) - zero_num(N-K, 0, 5) - zero_num(K, 0, 5);
  // two = zero_num(N, N-K, 2) - zero_num(K, 0, 2);
  five = zero_num(N, 5) - zero_num(N-K, 5) - zero_num(K, 5);
  two = zero_num(N, 2) - zero_num(N-K, 2) - zero_num(K, 2);
  printf("%d\n", COMPARE(five, two));

  // for(i=K;i>0;i--){
  //   temp = i;
  //   while(temp % 5 == 0) {five--; temp /= 5;}
  //   while(temp % 2 == 0) {two--; temp /= 2;}
  // }
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
