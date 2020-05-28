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

int stack[100000]={0};
int bound = 0;

void push(int val){
  stack[bound++] = val;
}

int pop(void){
  if(bound == 0) return -1;
  else return stack[--bound];
}

int top(void){
  return stack[bound-1];
}

void solve(int test_num){
  int i, N, track=1, ans_index=0;
  int arr[100000];
  char ans[100000];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", arr+i);
  }

  for(i=0;i<N;){
    if(arr[i] > top()){
      push(track++);
      ans[ans_index++] = '+';
    } else if (arr[i] == top()){
      pop();
      i++;
      ans[ans_index++] = '-';
    } else if (arr[i] < top()){
      printf("NO\n");
      bound = 0;
      return;
    }
  }

  for(i=0;i<ans_index;i++){
    printf("%c\n", ans[i]);
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
