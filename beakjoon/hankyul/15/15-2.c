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

void comb(int * arr, int index, int n, int r, int target){
	int i, j;
	if(r == 0){
		for(i=0;i<index;i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
	} else if (target == n) return;
	else{
		arr[index] = target+1;
		comb(arr, index+1, n, r-1, target+1);
		comb(arr, index, n, r, target+1);
	}
}


void solve(int test_num){
	int i;
	int N, M;
	int As[8];

	scanf("%d %d", &N, &M);

	comb(As, 0, N, M, 0);

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
