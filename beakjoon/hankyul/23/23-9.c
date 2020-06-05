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
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int i, j, k;
  int heights[100000] = {0};
  int N;

  while(1){
      bool check[100000] = {0};
      int min_heights;
      long long max_con = 0;
      long long cur_con = 0;
      int left, right;

      scanf("%d", &N);

      if(N == 0) break;

      for(i=0;i<N;i++){
        scanf("%d", heights+i);
      }

      for(i=0;i<N;i++){
        min_heights = heights[i];
        cur_con = 1;
        left = i-1; right = i+1;

        if(check[i] || min_heights == 0) continue;

        while(left >= 0 || right < N){
          if(left >= 0){
            if(heights[left] >= min_heights) {
              if(heights[left] == min_heights) check[left] = true;
              cur_con ++; left--;
            }
            else left = -1;
          }
          if(right < N){
            if(heights[right] >= min_heights) {
              if(heights[right] == min_heights) check[right] = true;
              cur_con ++; right++;
            }
            else right = N;
          }
        }
        // printf("[%d] cur_con : %d\n", i, cur_con);

        if(cur_con*min_heights > max_con) max_con = cur_con*min_heights;
      }

      printf("%lld\n", max_con);

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
