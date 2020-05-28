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

int stack[50];
int bound = 0;
int limit = 50;

void push(int val){
  stack[bound++] = val;
}

int pop(){
  if(bound == 0) return -1;
  else return stack[--bound];
}

int size(){
  // printf("size : %d\n", bound);
  return bound;
}

void solve(int test_num){
  int i;
  char input;
  char str[51];

  scanf("%s", str);

  for(i=0;i<strlen(str);i++){
    if(str[i] == '(') push('(');
    else if(pop()==-1){
      printf("NO\n");
      return;
    }
  }

  if(size() != 0) printf("NO\n");
  else printf("YES\n");
  bound = 0;
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
