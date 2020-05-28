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

void solve(int test_num){
  int i, j, N, two=0, five=0, ans = 0;
  int temp;
  scanf("%d", &N);

  for(i=1;i<=N;i++){
    temp = i;
    while(temp % 5 == 0) {five++; temp/=5;}
    while(temp % 2 == 0) {two++; temp/=2;}
  }

  printf("%d\n", COMPARE(two, five));
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
