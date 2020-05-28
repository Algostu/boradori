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

int stack[100000];
int bound = 0;
int limit = 100000;

void push(int val){
  stack[bound++] = val;
}

int pop(void){
  if(bound == 0) return -1;
  return stack[--bound];
}

void solve(int test_num){
  int i, N, ans=0, d;

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", &d);
    if(d == 0) pop();
    else push(d);
  }

  while((d = pop()) != -1) ans += d;

  printf("%d\n", ans);

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
