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
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int i, j, r, found, N, input[100];
  int fir_elem = 0;
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", input+i);
    if(i==0) fir_elem = input[i];
    input[i] -= fir_elem;
  }

  // MALLOC(q, sizeof(bool) * (input[1]+1));

  // for(i=0;i<(input[1]+1);i++) q[i] = false;

  // 나머지가 input[0]보다 작은 경우
  for(i=2;i<=fir_elem;i++){
    found = 0;
    r = fir_elem % i;
    for(j=1;j<N;j++){
      if((input[j] % i + r) % i != r){found=1; break;}
    }
    if(found == 0) {printf("%d ", i);}
  }
  // 나머지가 input[0]인 경우
  if(fir_elem < input[1]){
    for(i = fir_elem + 1 ; i<=input[1] ; i++){
      found = 0;
      for(j=1;j<N;j++){
        if(input[j] % i){found=1; break;}
      }
      if(found == 0) {printf("%d ", i);}
    }
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
