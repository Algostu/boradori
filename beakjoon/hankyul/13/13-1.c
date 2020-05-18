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
  int i, j, k, N, M, cards[100], ans=0, new_N = 0, temp;

  // get input N : num of cards, M : Limit of sum
  scanf("%d %d", &N, &M);

  // cards : integer < 100,000, new_N : M을 넘는 카드를 제외
  for(i=0;i<N;i++){
    scanf("%d", &temp);
    if(temp <= M-2){
      cards[new_N++] = temp;
    }
  }

  for(i=0;i<new_N-2;i++){
    for(j=i+1;j<new_N-1;j++){
      for(k=j+1;k<new_N;k++){
        temp = cards[i] + cards[j] + cards[k];
        if(temp > ans && temp <= M) ans = temp;
        if(ans == M){
          printf("%d\n", M);
          return;
        }
      }
    }
  }
  printf("%d\n", ans);

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
