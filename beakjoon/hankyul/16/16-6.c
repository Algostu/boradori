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

int max_cost(int index, int choice, int n, int (*nums)[500], int (*cost)[500]){
  int i, max_val = 0, temp;

  //debug
  //printf("index : %d, choice : %d min : %d\n", index, choice, max);
 	
  for(i=choice;i<choice+2;i++){
    if(index+1 == n) return nums[index][choice];
	else if(cost[index+1][i] != -1) temp = nums[index][choice] + cost[index+1][i];
    else {
      temp = nums[index][choice] + max_cost(index+1, i, n, nums, cost);
    }
	
	if(temp > max_val) max_val = temp;
  }
  
  cost[index][choice] = max_val;	

  return max_val;
}

void solve(int test_num){
  int i, j, N;
  int nums[500][500];
  int cost[500][500];
  scanf("%d", &N);

  for(i=0;i<N;i++){
  	for(j=0;j<=i;j++){
	  	scanf("%d", &nums[i][j]);
	    cost[i][j] = -1;
	  }
  }

  printf("%d\n", max_cost(0, 0, N, nums	, cost));
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

