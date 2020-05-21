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

void perm(int * arr, int index, int n, int r){
	int i, j, found = 0;

	if(index == r){
		for(i=0;i<index;i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
	} else{
		for(i=0;i<n;i++){
			arr[index] = i+1;
				perm(arr, index+1, n, r);
		}
	}
}

void solve(int test_num){
	int i;
	int N, M;
	int As[8];

	scanf("%d %d", &N, &M);

	perm(As, 0, N, M);

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
