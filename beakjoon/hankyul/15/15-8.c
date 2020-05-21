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

void comb(int * arr, int index, int n, int r, int target, int (*S)[20], int * min){
	int i, j, found=0, selected_sum = 0, unselected_sum = 0, un_arr[10], un_count=0;
	if(r == 0){
    //un_arr create
    for(i=0;i<n;i++){
      found = 0;
			for(j=0;j<index;j++){
        if(arr[j] == i) found = 1;
      }
      if(found == 0) un_arr[un_count++] = i;
		}

    for(i=0;i<index;i++){
      for(j=0;j<index;j++){
        if(i!=j){
          selected_sum += S[arr[i]][arr[j]];
          unselected_sum += S[un_arr[i]][un_arr[j]];
        }
      }
    }

    if(selected_sum - unselected_sum >= 0 && selected_sum - unselected_sum < *min) *min = selected_sum - unselected_sum;
	} else if (target == n) return;
	else{
		arr[index] = target;
		comb(arr, index+1, n, r-1, target+1, S, min);
		comb(arr, index, n, r, target+1, S, min);
	}
}

void solve(int test_num){
  int i, j, k, w, min = 10000000, N;
  int S[20][20], arr[10];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", (*(S+i)+j));
    }
  }

  comb(arr, 0, N, N/2, 0, S, &min);

  printf("%d\n", min);
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve();
  // }

  	solve(0);

	return 0;
}
