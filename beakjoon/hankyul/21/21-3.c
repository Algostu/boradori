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

int queue[1500];
int front = 0;
int rear = 0;

void push(int val){
  if(rear == 1500) rear = 0;
  queue[rear++] = val;
}

int pop(void){
  int ans = queue[front++];
  if(front == 1500) front = 0;
  return ans;
}

int size(void){
  if(front < rear) return rear - front;
  else return 1500 - (front - rear);
}

void solve(int test_num){
  int N, K;
  int i;

  scanf("%d %d", &N, &K);
  for(i=0;i<N;i++){
    queue[i] = i+1;
  }
  rear = N;

  printf("<");
  while(size()!=1){
    for(i=0;i<K-1;i++){
      push(pop());
    }
    printf("%d, ", pop());
  }

  printf("%d>\n", pop());
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
