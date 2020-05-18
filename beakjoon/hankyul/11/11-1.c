#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 0 : ((X) == (Y) ? 0 : 1)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int factorial(int n){
  if(n == 0) return 1;
  else if(n == 1) return 1;
  else return n * factorial(n-1);
}

void solve(int test_num){
  int N;

  scanf("%d", &N);

  printf("%d\n", factorial(N));
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
