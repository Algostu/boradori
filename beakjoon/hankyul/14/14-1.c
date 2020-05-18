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

void solve(int test_num){
	int i, j, temp, smallest=100, N, As[1000];
	scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", As+i);
  }

  for(i=0;i<N-1;i++){
    smallest = i;
    for(j=i+1;j<N;j++){
      if(As[smallest] > As[j]) smallest = j;
    }
    SWAP(As[smallest], As[i], int);
  }

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
