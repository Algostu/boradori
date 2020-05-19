#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void merge(int* arr, int l, int m, int r){
  int L[500000], R[500000];
  int i, j, k, temp;
  int count_L = m - l + 1;
  int count_R = r - m;

  for(i=0;i<count_L;i++){
    L[i] = arr[l+i];
  }

  for(i=0;i<count_R;i++){
    R[i] = arr[m+1+i];
  }

  i = j = 0;
  k = l;

  while(i<count_L && j < count_R){
    if(L[i] < R[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i<count_L){
    arr[k++] = L[i++];
  }

  while(j<count_R){
    arr[k++] = R[j++];
  }

  // for(i=0;i<count_L+count_R;i++){
  //   printf("%d ", arr[i]);
  // }
}

void merge_sort(int * arr, int l, int r){
  if(l<r){
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}
void solve(int test_num){
	int i, j, temp, smallest=100, N, As[1000000];
	scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", As+i);
  }

  merge_sort(As, 0, N-1);

  for(i=0;i<N;i++){
    printf("%d\n", As[i]);
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
