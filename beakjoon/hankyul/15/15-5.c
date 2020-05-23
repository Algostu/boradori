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
  fprintf(stderr, “mallc error”); exit(EXIT_FAILURE);\
}

typedef int (*board)[14];

void mark(board arr, int a, int b, int size, int * mark_num){
	int i;
	int count = 0;

  // y = x - a + b
  for(i = -14; i<14;i++){
		if(a + i >= 0 && a + i < size && b + i >= 0 && b + i < size){
			if (arr[b+i][a+i] == 1)count++;
			arr[b+i][a+i] = 0;
		}
	}

  // y = -x + a + b
	for(i = -14; i<14;i++){
		if(a + i >= 0 && a + i < size && b - i >= 0 && b - i < size){
			if (arr[b-i][a+i] == 1) count++;
			arr[b-i][a+i] = 0;
		}
	}

  // x = a
	for(i = 0; i < size;i++){
		if(arr[i][a] == 1)count++;
		arr[i][a] = 0;
	}

  // y = b
	for(i = 0; i < size;i++){
		if(arr[b][i] == 1) count++;
		arr[b][i] = 0;
	}

	*mark_num = count;
}

void n_queen(board arr, int index, int n, const int r, int remaining, int * ans){
	int i, j, q, w, temp=0;
	int copy_arr[14][14];

	memcpy(copy_arr, arr, sizeof(int)*14*n);

	if(r == 0){
		(*ans)++;
    // debug
    // printf("%========================\n", r);
    // for(q = 0; q < n; q++){
    //   for(w = 0; w < n; w++){
    //     printf("%d ", arr[q][w]);
    //   }
    //   printf("\n");
    // }
    // printf("ans : %d\n", *ans);
    return;
	} else if(remaining == 0) {
		//printf("r : %d\n", r);
		return;
	}
	else{
		for(j=0;j<n;j++){
			if(arr[index][j] == 1) {

				copy_arr[index][j] = 0;

        mark(arr, j, index, n, &temp);

        arr[index][j] = 2;

        n_queen(arr, index+1, n, r-1, remaining-temp, ans);

        memcpy(arr, copy_arr, sizeof(int)*14*n);

    		n_queen(arr, index, n, r, remaining-1, ans);
				return;
			}
		}

	}
}

void solve(int test_num){
	int i, j;
	int N;
	int chess[14][14];
	int ans = 0;
	scanf("%d", &N);

	for(i=0;i<14;i++){
		for(j=0;j<14;j++){
			chess[i][j] = 1;
		}
	}
	n_queen(chess, 0, N, N, N*N, &ans);

	printf("%d\n", ans);
}

int main(){
  // int i, N;
  // scanf(“%d”, &N);
  // for(i=0;i<N;i++){
  //     solve();
  // }

  	solve(0);

	return 0;
}
