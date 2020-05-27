#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int comp(const void * a, const void * b){
  return (*(int*)a) - (*(int*)b);
}
void solve(int test_num){
  int i, N, sum = 0, total_sum = 0;
  int A[1000];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", A+i);
  }

  qsort(A, N, sizeof(int), comp);

  for(i = 0; i<N;i++){
    sum += A[i];
    total_sum += sum;
  }

  printf("%d\n", total_sum);
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
