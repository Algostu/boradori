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

int pop_front(void){
    int ans;
    if(first == rear) ans = -1;
    else ans = deque[first++];
    if(first==12000) first = 0;

    return ans;
}

int pop_back(void){
  int ans;
  if(first == rear) ans = -1;
  else {
    if(rear == 0) rear = 12000;
    ans = deque[--rear];
  }

  return ans;
}

int size(void){
  if(first <= rear) return rear - first;
  else return 12000-(first-rear);
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
  int N, M, i, j, ans = 0, target, norm, cur, dis, targets[50];
  scanf("%d %d", &N, &M);

  for(i=0;i<N;i++){
    deque[i] = i+1;
  }

  rear = N;

  for(i=0;i<M;i++){
    scanf("%d", &targets[i]);
  }

  int n;

  for(i=0;i<M;i++){
    target = targets[i];
    dis = 0;

    n = size();

    while(1){
      cur = pop_front();
      if(cur == target) {break;}
      else push_back(cur);
      dis++;
    }

    if (dis <= n/2){
      ans += dis;
    } else {
      ans += (n-dis);
    }

  }
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
