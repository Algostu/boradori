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
	int i, j, temp, N;
  int num[10];

  memset(num, 0, 10*sizeof(int));

  scanf("%d", &N);

  while(1){
    if(N<10) break;
    num[N%10]++;
    N /= 10;
  }
  num[N%10]++;

  for(i=9;i>=0;i--){
    for(j=0;j<num[i];j++){
      printf("%d", i);
    }
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
