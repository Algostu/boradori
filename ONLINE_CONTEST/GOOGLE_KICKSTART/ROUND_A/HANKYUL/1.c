#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 0 : ((X) == (Y) ? 0 : 1)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int i, j, N, K, A[200000], k, ans=0, count=0;
  scanf("%d %d", &N, &K);

  for(i=0;i<N;i++){
    scanf("%d", A+i);
  }

  for(i=0;i<N;i++){
    count = 0;
    if(A[i]==K)
      for(j=i;j<i+K-1;j++){
        if(A[j] != A[j+1] + 1){
          break;
        } else count++;
      }
      if(count == K-1) {ans++; i += (K-1);}
  }
  printf("Case #%d: %d\n", test_num, ans);
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(i+1);
  }

  // solve(0);

	return 0;
}
