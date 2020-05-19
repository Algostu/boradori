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
	int i, j, temp, smallest=100, N;
  int count[10001];

  memset(count, 0, 10001*sizeof(int));

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", &temp);
    count[temp]++;
  }

  for(i=1;i<10001;i++){
    for(j=0;j<count[i];j++){
      printf("%d\n", i);
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
