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

void solve(int test_num){
  int i, j, N, temp, num_divs=0;
  int ring[100];
  int divs[1000];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", ring+i);
  }

  for(i=2;i<=ring[0];i++){
    if(ring[0]%i == 0) divs[num_divs++] = i;
  }

  for(i=1;i<N;i++){
    temp = ring[0];
    for(j=num_divs-1;j>=0;j--){
      if(ring[i] % divs[j] == 0){
        temp /= divs[j];
        ring[i] /= divs[j];
        break;
      }
    }
    printf("%d/%d\n", temp, ring[i]);
  }
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
