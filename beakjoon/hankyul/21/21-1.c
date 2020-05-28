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

int queue[10000];
int bound = 0;
int out = 0;

void push(int val){
  queue[bound++] = val;
}

void pop(void){
  int i;
  if(bound==0) printf("-1\n");
  else {
    printf("%d\n", queue[0]);
    bound--;
    for(i=0;i<bound;i++){
      queue[i] = queue[i+1];
    }
  }
}

void size(void){
  printf("%d\n", bound);
}

void empty(void){
  if(bound == 0) printf("1\n");
  else printf("0\n");
}

void front(void){
  if(bound == 0) printf("-1\n");
  else printf("%d\n", queue[0]);
}

void back(void){
  if(bound==0) printf("-1\n");
  else printf("%d\n", queue[bound-1]);
}

void solve(int test_num){
  int N, i, d;
  char input[20];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%s", input);
    if(strcmp(input, "push")==0){
      scanf("%d", &d);
      push(d);
    } else if(strcmp(input, "front")==0){
      front();
    } else if(strcmp(input, "back")==0){
      back();
    } else if(strcmp(input, "pop")==0){
      pop();
    } else if(strcmp(input, "empty")==0){
      empty();
    } else if(strcmp(input, "size")==0){
      size();
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
