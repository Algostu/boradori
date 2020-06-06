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

typedef struct __deque{
  int queue[100000];
  int first;
  int rear;
} deque;


void push_front(deque * que, int val){
  if(que->first == que->rear) {
    que->queue[que->rear++] = val;
    if(que->rear == 100000) que->rear = 0;
  }
  else {
    if(que->first == 0) que->first = 100000;
    que->queue[--que->first] = val;
  }
}

void push_back(deque * que, int val){
  que->queue[que->rear++] = val;
  if(que->rear == 100000) que->rear = 0;
}

int pop_front(deque * que){
    int ans;
    if(que->first == que->rear) ans = -1;
    else ans = que->queue[que->first++];
    if(que->first==100000) que->first = 0;

    return ans;
}

int pop_back(deque * que){
  int ans;
  if(que->first == que->rear) ans = -1;
  else {
    if(que->rear == 0) que->rear = 100000;
    ans = que->queue[--que->rear];
  }

  return ans;
}

int size(deque * que){
  if(que->first <= que->rear) return que->rear - que->first;
  else return 100000-(que->first-que->rear);
}

void empty(deque * que){
  if(que->first == que->rear) printf("1\n");
  else printf("0\n");
}

void front(deque * que){
  if(que->first == que->rear) printf("-1\n");
  else printf("%d\n", que->queue[que->first]);
}

void back(deque * que){
  if(que->first == que->rear) printf("-1\n");
  else if (que->rear==0) printf("%d\n", que->queue[100000-1]);
  else printf("%d\n", que->queue[que->rear-1]);
}

int a_to_i(char * arr){
  int i, ans = 0, base = 1;
  for(i=strlen(arr)-1;i>=0;i--){
    ans += (base * (arr[i]-('1'-1)));
    base *= 10;
  }
  return ans;
}

void solve(int test_num){
  deque q;
  int N, M, i, j, mode=1;
  char func[100001], input[11000000];
  // char func[100001], input[100001];
  char * temp;
  // input function R | D
  scanf("%s", func);

  // size of input array
  scanf("%d", &N);

  // input array
  scanf("%s", input);

  i = 0;
  temp = strtok(input, "[],");

  while(temp != NULL){
    q.queue[i++] = a_to_i(temp);
    temp = strtok(NULL, "[],");
  }

  q.rear = N;
  q.first = 0;

  // debug input array
  // for(i=0;i<N;i++){
  //   printf("%d ", q.queue[i]);
  // }
  // printf("\n");

  // main logic start
  for(i=0;i<strlen(func);i++){
    // flip mode : 1 -> original 0 -> reverse
    if(func[i] == 'R'){
      mode = mode ^ 1;
    }
    else if(mode == 1){
      if(pop_front(&q)==-1){
          printf("error\n");
          return;
      }
    } else {
      if(pop_back(&q)==-1){
          printf("error\n");
          return;
      }
    }
  }

  //debug
  // printf("mode : %d size : %d\n", mode, size(&q));

  // size
  int n = size(&q);

  // N == 0
  if (n==0){
    printf("[]\n");
  }
  // N > 0 reverse print
  else if(mode == 0){
    printf("[");
    for(i=0;i<n-1;i++){
      printf("%d,",pop_back(&q));
    }
    printf("%d]\n", pop_back(&q));
  }
  // N > 0 original print
  else if (mode == 1){
    printf("[");
    for(i=0;i<n-1;i++){
      printf("%d,",pop_front(&q));
    }
    printf("%d]\n", pop_front(&q));
  }
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
