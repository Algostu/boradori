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

int GCD(int a, int b){
    int i, smaller = COMPARE(a, b);

    for(i = smaller;i>0;i--){
      if(a%i == 0 && b%i==0) return i;
    }
}

void solve(int test_num){
  int A, B;
  scanf("%d %d", &A, &B);
  int gcd = GCD(A, B);
  int lcm = gcd * (A / gcd) * (B / gcd);
  printf("%d\n%d\n", gcd, lcm);
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
