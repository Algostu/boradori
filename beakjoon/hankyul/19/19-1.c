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
  char * ans[3] = {"factor", "multiple", "neither"};
  int input[2];

  scanf("%d %d", input, input+1);

  while(input[0] != 0 && input[1] != 0){
    if(input[1] % input[0] == 0) printf("%s\n", ans[0]);
    else if(input[0] % input[1] == 0) printf("%s\n", ans[1]);
    else printf("%s\n", ans[2]);
    scanf("%d %d", &input[0], &input[1]);
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
