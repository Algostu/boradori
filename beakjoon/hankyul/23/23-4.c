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

long long dp(int A, int B, int C, long long * memo){
  long long ans, a, b;
  // printf("A : %d B : %d C : %d\n", A, B, C);
  if(memo[B] != -1) ans = memo[B];
  else if (B == 0) ans = A % C;
  else {
    a = dp(A, B-1, C, memo);
    b = dp(A, B-1, C, memo);
    ans = (a * b) % C;
  }

  memo[B] = ans;

  return ans;

}
void solve(int test_num){
  int A, B, C;
  long long ans = 1;
  long long memo[1000];
  scanf("%d %d %d", &A, &B, &C);

  for(int i=0;i<1000;i++){
    memo[i] = -1;
  }

  for(int i=0;i<32;i++){
    if((B >> i) & 1){
      ans *= dp(A, i, C, memo);
      ans = ans % C;
    }
  }
  printf("%lld\n", ans % C);
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
