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
  rear = front = 0;
  int N, M, i, j, count[10][100], found = 0, ans = 0, total = 0, remaining=0, min=999, min_index = -1, count_index, target_priority;
  task temp;
  scanf("%d %d", &N, &M);

  for(i=0; i<10;i++) count[i][0] = 0;

  for(i=0;i<N;i++){
      queue[i].task_no = i;
      scanf("%d", &queue[i].priority);
      count[queue[i].priority][++count[queue[i].priority][0]] = i;
  }

  rear = N;
  target_priority = queue[M].priority;
  i = 9;
  // first least one!
  for(i=9;i>target_priority;i--){
    if(count[i][0] > 0){
      min_index = count[i][count[i][0]];
      i--;
      break;
    }
  }
  int temp_index;

  for(i;i>target_priority;i--){
    if(count[i][0] > 0){
      temp_index = count[i][1];
      if(temp_index>min_index){
        min_index = count[i][count[i][0]];
        continue;
      }
      for(j=1;j<count[i][0]+1;j++){
        if(count[i][j] > min_index){
          min_index = temp_index;
          break;
        }
        temp_index = count[i][j];
      }
    }
  }

  // printf("min_index : %d\n", min_index);

  for(i=0;i<N;i++){
    temp = pop();
    // printf("temp.priority : %d temp.task_no : %d\n", temp.priority, temp.task_no);
    if(temp.priority > target_priority){
      ans++;
      push(temp);
    }
    else if(temp.priority == target_priority) {
      push(temp);
    }
  }

  // for(i=front;i<rear;i++){
  //   printf("queue[%d].task_no : %d queue[%d].priority : %d\n", i, queue[i].task_no, i, queue[i].priority);
  // }
  // printf("min : %d min_index : %d total : %d \n", min, min_index, total);

  if(min_index == -1){
    while(1){
      temp = pop();
      if(temp.task_no == M){
        printf("%d\n", ans+1);
        return;
      } else if (temp.priority == target_priority){
        ans++;
      }
    }
  } else {
    while(1){
      temp = pop();
      if(found == 1 && temp.task_no == M){
        printf("%d\n", ans+1);
        return;
      } else if (found == 0 && temp.task_no == min_index){
        found = 1;
      } else if (found == 0 && temp.priority == target_priority){
        push(temp);
      } else if (found == 1 && temp.priority == target_priority){
        ans++;
      }
    }

  }

  // count_index = max;

  // while(target_priority != count_index){
  //   temp = pop();
  //   if(temp.priority == count_index){
  //     count[count_index]--;
  //     ans++;
  //     if(count[count_index] == 0) while(count[--count_index] == 0);
  //   } else push(temp);
  // }
  //
  // while(1){
  //   temp = pop();
  //   if(temp.priority == count_index){
  //     ans++;
  //     if(temp.task_no == M) {
  //       printf("%d\n", ans);
  //       return;
  //     }
  //   } else push(temp);
  // }
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
