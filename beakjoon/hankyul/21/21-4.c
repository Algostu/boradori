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

typedef struct __task{
  int priority;
  int task_no;
} task;

task queue[1500];
int front = 0;
int rear = 0;

void push(task val){
  if(rear == 1500) rear = 0;
  queue[rear++] = val;
}

task pop(void){
  task ans = queue[front++];
  if(front == 1500) front = 0;
  return ans;
}

int size(void){
  if(front < rear) return rear - front;
  else return 1500 - (front - rear);
}

void solve(int test_num){
  int N, M, i, j, count[10], max = 0, ans = 0, count_index, target_priority;
  task temp;
  scanf("%d %d", &N, &M);

  for(i=0; i<10;i++) count[i] = 0;

  for(i=0;i<N;i++){
      queue[i].task_no = i;
      scanf("%d", &queue[i].priority);
      count[queue[i].priority]++;
      if(max < queue[i].priority) max = queue[i].priority;
  }

  rear = N;
  target_priority = queue[M].priority;
  count_index = max;

  while(target_priority != count_index){
    temp = pop();
    if(temp.priority == count_index){
      count[count_index]--;
      ans++;
      if(count[count_index] == 0) while(count[--count_index] == 0);
    } else push(temp);
  }

  while(1){
    temp = pop();
    if(temp.priority == count_index){
      ans++;
      if(temp.task_no == M) {
        printf("%d\n", ans);
        return;
      }
    } else push(temp);
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
