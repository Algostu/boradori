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
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

int comp(const void * a, const void * b){
  int c = (*(int *) a);
  int d = (*(int *) b);
  if(c < d) return -1;
  else if (c==d) return 0;
  else return 1;
}

void solve(int test_num){
  int i;
  int N;
  int M;
  int * arr, * arr2;

  scanf("%d", &N);

  arr = (int*)calloc(N, sizeof(int));

  for(i=0;i<N;i++){
    scanf("%d", arr+i);
  }

  scanf("%d", &M);

  arr2 = (int*)calloc(M, sizeof(int));

  for(i=0;i<M;i++){
    scanf("%d", arr2+i);
  }

  qsort(arr, N, sizeof(int), comp);

  for(i=0;i<M;i++){
    bool find = false;
    int left = 0;
    int right = N-1;
    int mid;
    while(left <= right){
      mid = (left + right) / 2;
      if(arr[mid] == arr2[i]){
        find = true;
        break;
      } else if (arr[mid] < arr2[i]) left = mid+1;
      else right = mid-1;
    }

    printf("%d", find);

    if(i!=M-1) printf("\n");
  }

  free(arr);
  free(arr2);
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
