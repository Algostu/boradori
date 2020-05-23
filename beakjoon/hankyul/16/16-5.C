#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int min_cost(int index, int not_index, int n, int (*color)[3], int (*cost)[3]){
  int i, min=1000000;

  //debug
  // printf("index : %d, n : %d min : %d\n", index, n, min);

  for(i=0;i<3;i++){
    if(i==not_index) continue;
    if(cost[index][i] != -1 && cost[index][i] < min) min = cost[index][i];
    else if (index+1 == n && color[index][i] < min) min = color[index][i];
    else if (index+1 != n) {
      cost[index][i] = color[index][i] + min_cost(index+1, i, n, color, cost);
      if(cost[index][i] < min) min = cost[index][i];
    }
  }


  return min;
}

void solve(int test_num){
  int i, N;
  int colors[1001][3];
  int cost[1001][3];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d %d %d", &colors[i][0], &colors[i][1], &colors[i][2]);
    cost[i][0] = cost[i][1] = cost[i][2] = -1;
  }

  printf("%d\n", min_cost(0, -1, N, colors, cost));
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
