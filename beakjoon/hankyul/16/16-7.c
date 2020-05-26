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

int max_cost(int index, int count, int n, int *stairs, int (*cost)[2]){
  int i, max_val = 0, temp=-1;
  // printf("%d================\n", index);
  // for(i=0;i<n;i++){
  //   printf("%d %d\n", cost[i][0], cost[i][1]);
  // }

  if(index + 1 == n) {
    cost[index][0] = cost[index][1] = stairs[index];
    return stairs[index];
  }

  for(i=1;i<3;i++){
    if(count == 1 && i==1) continue;
    if(cost[index][i-1] != -1) temp = cost[index][i-1];
    else if(i==1) {
      temp = max_cost(index+i, count+1, n, stairs, cost);

      if (temp != 0) temp += stairs[index];

      // if(cost[index+1][0] != -1 && cost[index+1][1] != -1) cost[index][0] = temp;
      cost[index][i-1] = temp;
    }
    else if (index + 2 != n) {
      temp = max_cost(index+i, 0, n, stairs, cost);

      if (temp != 0) temp += stairs[index];
      // if(cost[index+2][0] != -1 && cost[index+2][1] != -1) cost[index][1] = temp;
      cost[index][i-1] = temp;
    }

    if(temp > max_val) max_val = temp;
  }

  return max_val;
}

void solve(int test_num){
  int i, j, N;
  int stairs[300];
  int cost[300][2];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", stairs+i);
    cost[i][0] = cost[i][1] = -1;
  }

  printf("%d\n", COMPARE(max_cost(0, 0, N, stairs, cost), max_cost(1, 0, N, stairs, cost)));

  for(i=0;i<N;i++){
    printf("%d %d\n", cost[i][0], cost[i][1]);
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
