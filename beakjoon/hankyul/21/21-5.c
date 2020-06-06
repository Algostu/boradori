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

int deque[12000];
int first = 0;
int rear = 0;

void push_front(int val){
  if(first == rear) {
    deque[rear++] = val;
    if(rear == 12000) rear = 0;
  }
  else {
    if(first == 0) first = 12000;
    deque[--first] = val;
  }
}

void push_back(int val){
  deque[rear++] = val;
  if(rear == 12000) rear = 0;
}

void pop_front(void){
    if(first == rear) printf("-1\n");
    else printf("%d\n", deque[first++]);
    if(first==12000) first = 0;
}

void pop_back(void){
  if(first == rear) printf("-1\n");
  else {
    if(rear == 0) rear = 12000;
    printf("%d\n", deque[--rear]);
  }
}

void size(void){
  if(first <= rear) printf("%d\n", rear - first);
  else printf("%d\n", 12000-(first-rear));
}

void empty(void){
  if(first == rear) printf("1\n");
  else printf("0\n");
}

void front(void){
  if(first == rear) printf("-1\n");
  else printf("%d\n", deque[first]);
}

void back(void){
  if(first == rear) printf("-1\n");
  else if (rear==0) printf("%d\n", deque[12000-1]);
  else printf("%d\n", deque[rear-1]);
}

void solve(int test_num){
  first = rear = 0;
  int N, i, parm;
  char op[20];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%s", op);

    if(strcmp(op, "push_back")==0){
      scanf("%d", &parm);
      push_back(parm);
    } else if(strcmp(op,"push_front")==0){
      scanf("%d", &parm);
      push_front(parm);
    } else if(strcmp(op,"pop_front")==0){
      pop_front();
    } else if(strcmp(op,"pop_back")==0){
      pop_back();
    } else if(strcmp(op,"size")==0){
      size();
    } else if(strcmp(op,"empty")==0){
      empty();
    } else if(strcmp(op,"front")==0){
      front();
    } else if(strcmp(op,"back")==0){
      back();
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
