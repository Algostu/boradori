#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 0 : ((X) == (Y) ? 0 : 1)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void hanoi(int n, int from, int through, int to, char *arr, int* size){
  if(n==1){
    arr[*size] = from*10;
    arr[*size] += to;
    (*size) += 1;

  } else{
    hanoi(n-1, from, to, through, arr, size);

    arr[*size] = from*10;
    arr[*size] += to;
    (*size) += 1;

    hanoi(n-1, through, from, to, arr, size);
  }
}

void solve(int test_num){
  int K;
  char arr[1100000];
  int size = 0;
  int i;
  scanf("%d", &K);

  hanoi(K, 1, 2, 3, arr, &size);
  printf("%d\n", size);
  // for(i=0;i<size;i++){
  //   printf("%d %d\n", arr[i]/10, arr[i]%10);
  // }
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(0);
  // }

  solve(0);

	return 0;
}
