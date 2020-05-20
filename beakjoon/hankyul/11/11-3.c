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

typedef char (*C2ARR2188)[2188];

void star(int N, C2ARR2188 arr, int r, int c){
	int i, j;
	if(N==1){
		arr[r][c] = '*';
	} else{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(i==1 && j==1) continue;

				star(N/3, arr, r + i*N/3, c + j*N/3);
			}
		}
	}

}

void solve(int test_num){
	int N, i, j;
	char some_place[2187][2188];


	scanf("%d", &N);

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			some_place[i][j] = 32;
		}
		some_place[i][N] = '\0';
	}

	star(N, some_place, 0, 0);

	for(i=0;i<N;i++){
		printf("%s\n", some_place[i]);
	}
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
