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

void merge(int (*arr)[2], int l, int m, int r){
  int L[50000][2], R[50000][2];
  int i, j, k, temp;
  int count_L = m - l + 1;
  int count_R = r - m;

  for(i=0;i<count_L;i++){
    L[i][0] = arr[l+i][0];
    L[i][1] = arr[l+i][1];
  }

  for(i=0;i<count_R;i++){
    R[i][0] = arr[m+1+i][0];
    R[i][1] = arr[m+1+i][1];
  }

  i = j = 0;
  k = l;

  while(i<count_L && j < count_R){
    if(L[i][1] < R[j][1] || (L[i][1] == R[j][1] && L[i][0] < R[j][0])){
      arr[k][0] = L[i][0];
      arr[k][1] = L[i][1];
      i++;
    } else{
      arr[k][0] = R[j][0];
      arr[k][1] = R[j][1];
      j++;
    }
    k++;
  }

  while(i<count_L){
    arr[k][0] = L[i][0];
    arr[k++][1] = L[i++][1];
  }

  while(j<count_R){
    arr[k][0] = R[j][0];
    arr[k++][1] = R[j++][1];
  }

  // for(i=0;i<count_L+count_R;i++){
  //   printf("%d ", arr[i]);
  // }
}

void merge_sort(int (*arr)[2], int l, int r){
  if(l<r){
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

void solve(int test_num){
	int i, j, temp, N;
  int point[100000][2];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d %d", point[i], point[i]+1);
  }

  merge_sort(point, 0, N-1);

  for(i=0;i<N;i++){
    printf("%d %d\n", point[i][0], point[i][1]);
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
