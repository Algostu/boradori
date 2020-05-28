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
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int stack[10000];
int bound = 0;
int limit = 10000;

void push(int val){
  if (bound==limit){
    printf("exceed limit");
    return;
  }
  stack[bound++] = val;
  return;
}

void pop(void){
  if (bound==0) { printf("-1\n"); return; }
  printf("%d\n", stack[--bound]);
}

void size(void){
  printf("%d\n", bound);
}

void empty(void){
  if (bound==0)  printf("1\n");
  else printf("0\n");
}

void top(void){
  if(bound==0) printf("-1\n");
  else printf("%d\n", stack[bound-1]);
}

void solve(int test_num){
  int i, N, val;
  char op[10];
  scanf("%d", &N);
  for(i=0; i<N;i++){
    scanf("%s", op);
    if(strcmp(op, "push")==0){
      scanf("%d", &val);
      push(val);
    }
    else if(strcmp(op, "top")==0){
      top();
    }
    else if(strcmp(op, "size")==0){
      size();
    }
    else if(strcmp(op, "empty")==0){
      empty();
    }
    else if(strcmp(op, "pop")==0){
      pop();
    }
  }

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
