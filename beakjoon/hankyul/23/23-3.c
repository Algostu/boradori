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

bool is_all(int (*arr)[2187], int r, int c, int first, size_t size){
  bool ans = true;
  int i, j;
  // bool first = arr[r][c];
  for(i=r;i<r+size;i++){
    for(j=c;j<c+size;j++){
      if(first != arr[i][j]) { ans = false; break; }
    }
  }
  return ans;
}

void paper(int (*arr)[2187], int r, int c, size_t size, int * ans){
  int smaller = size / 3, i, j;
  // printf("before : r : %d c : %d size : %d ans : %d\n", r, c, size, ans);
  if(is_all(arr, r, c, -1, size) == 1) ans[0]++;
  else if (is_all(arr, r, c, 0, size) == 1) ans[1]++;
  else if (is_all(arr, r, c, 1, size) == 1) ans[2]++;
  else if(size == 1 && arr[r][c] == -1) ans[0]++;
  else if(size == 1 && arr[r][c] == 0) ans[1]++;
  else if(size == 1 && arr[r][c] == 1) ans[2]++;
  else {
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        paper(arr, r+i*smaller, c+j*smaller, smaller, ans);
      }
    }
  }
  // printf("after : r : %d c : %d size : %d ans : %d\n", r, c, size, ans);
  // return ans;
}

void solve(int test_num){
  int i, j, N, temp, ans[3] = {0};
  int arr[2187][2187];

  // initial paper size
  scanf("%d", &N);

  // get color info
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d", &temp);
      arr[i][j] = temp;
    }
  }
  paper(arr, 0, 0, N, ans);
  printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
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
