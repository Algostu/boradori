#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

typedef struct __object{
  int w;
  int v;
  int in;
} object;

int high_value(object * bag, int index, int N, int K, object * arr){
  int max = bag->v, temp;

  for(int i = index; i < N; i++){
    if(arr[i].in == 0 && bag->w + arr[i].w <= K){
      bag->w += arr[i].w;
      bag->v += arr[i].v;
      arr[i].in = 1;
      temp = high_value(bag, i+1, N, K, arr);
      bag->w -= arr[i].w;
      bag->v -= arr[i].v;
      arr[i].in = 0;
      if(max < temp) max = temp;
    }
  }
  return max;
}

void solve(int test_num){
  int N, K;
  object objs[100];
  object bag = {0, 0};

  scanf("%d %d", &N, &K);

  for(int i = 0; i<N;i++){
    scanf("%d %d", &objs[i].w, &objs[i].v);
    objs[i].in = 0;
  }

  printf("%d\n", high_value(&bag, 0, N, K, objs));
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
