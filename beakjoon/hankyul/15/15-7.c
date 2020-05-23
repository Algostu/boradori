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

void find_min_max(int * arr, int index, int * As, int * operators, int n, int r, int * min, int * max){
	int i, j, found = 0;
  int result = 0;
	if(index == r){
    result = As[0];
    for(i=0;i<n;i++){
      switch (arr[i]){
        case 0:
          result += As[i+1];
          break;
        case 1:
          result -= As[i+1];
          break;
        case 2:
          result *= As[i+1];
          break;
        case 3:
          result /= As[i+1];
          break;
      }
      // printf("%d\n", arr[i]);
    }

    if(result < *min) *min = result;
    if(result > *max) *max = result;
    return;
	} else{
		for(i=0;i<4;i++){
      if(operators[i] == 0) continue;
			else{
				arr[index] = i;
        operators[i]--;
				find_min_max(arr, index+1, As, operators, n, r, min, max);
        operators[i]++;
			}
		}
	}
}

void solve(int test_num){
  int i, j, k, w, N, As[11], operators[4], arr[10];
  int min = 1000000000, max = -1000000000;

  // get input N : number of input
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", As+i);
  }

  for(i=0;i<4;i++){
    scanf("%d", operators+i);
  }

  find_min_max(arr, 0, As, operators, N-1, N-1, &min, &max);

  printf("%d\n%d\n", max, min);
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
