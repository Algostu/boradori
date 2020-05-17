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
  int i, j, k, q, w, N, M, temp, index = 0, ans=64;
  char board[50][51];
  char color[2] = {'W', 'B'};
  // get input N : target number
  scanf("%d %d", &N, &M);

  for(i=0;i<N;i++){
    scanf("%s", board[i]);
  }

  for(i=0;i<N-8+1;i++){
    for(j=0;j<M-8+1;j++){
        for(k=0;k<2;k++){
          temp = 0; index = k;
          for(q=0;q<8;q++){
            for(w=0;w<8;w++){
              if(board[i+q][j+w] != color[index]) temp++;
              index ^= 1;
            }
            index ^= 1;
          }

          if(ans > temp) ans = temp;
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
