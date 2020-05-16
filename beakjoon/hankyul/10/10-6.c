#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
  int i, x, y, w, h;
  int dist[4] = {0};
  int min = 1000;
  scanf("%d %d %d %d", &x, &y, &w, &h);

  dist[0] = x;
  dist[1] = w - x;
  dist[2] = y;
  dist[3] = h - y;

  for(i=0;i<4;i++){
    if(min > dist[i]) min = dist[i];
  }
  printf("%d", min);
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
