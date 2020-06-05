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

bool is_all(bool (*arr)[128], int r, int c, size_t size){
  bool ans = true;
  int i, j;
  bool first = arr[r][c];
  for(i=r;i<r+size;i++){
    for(j=c;j<c+size;j++){
      if(first != arr[i][j]) { ans = false; break; }
    }
  }
  return ans;
}

void paper(bool (*arr)[128], int r, int c, size_t size){
  int smaller = size / 2, i, j;
  // printf("before : r : %d c : %d size : %d ans : %d\n", r, c, size, ans);
  if(is_all(arr, r, c, size) == 1) printf("%d", arr[r][c]);
  // else if (is_all(arr, r, c, 1, size) == 1) printf("1");
  else if(size == 1) printf("%d", arr[r][c]);
  // else if(size == 1 && arr[r][c] == 1) printf("1");
  else {
    printf("(");
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        paper(arr, r+i*smaller, c+j*smaller, smaller);
      }
    }
    printf(")");
  }
  // printf("after : r : %d c : %d size : %d ans : %d\n", r, c, size, ans);
  // return ans;
}

void solve(int test_num){
  int i, j, N, ans[2] = {0};
  bool arr[128][128];
  char temp, input[128];
  // initial paper size
  scanf("%d", &N);

  // get color info
  for(i=0;i<N;i++){
    scanf("%s", input);
    for(j=0;j<N;j++){
      arr[i][j] = input[j] - ('0' - 0);
    }
  }

  paper(arr, 0, 0, N);
  printf("\n");
  // printf("%d\n%d\n", ans[0], ans[1]);
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
