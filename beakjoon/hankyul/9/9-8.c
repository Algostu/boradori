#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int sigma(int n){
  return n * (n + 1 ) / 2;
}

void solve(int test_num){
  int x, y, i, distance, where=1, move = 1, count = 1;
  scanf("%d %d", &x, &y);

  distance = y - x;

  while(where < distance){
    for(i=1;i>-2;i--){
      /* slow version */
      // if(sigma(i+move) <= (distance - where)){
      //   move += i;
      //   where += move;
      //   count++;
      //   break;
      // }

      /* fast version */
      if(sigma(i+move) < (distance - where)){
        move += i;
        where += move;
        count++;
        break;
      } else if (sigma(i+move) == (distance - where)){
        printf("%d\n", count+i+move);
        return;
      }
    }
  }

  printf("%d\n", count);
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }
	return 0;
}
