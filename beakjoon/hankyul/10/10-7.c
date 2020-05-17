#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

typedef struct __point{
  int x;
  int y;
} point;

void solve(int test_num){
  int i, x[2]={0}, x_c[2]={0}, y[2]={0}, y_c[2]={0};
  point p[4];
  for(i=0;i<3;i++){
    scanf("%d %d", &p[i].x, &p[i].y);
  }

  for(i=0;i<3;i++){
      if(i==0){
        x[0] = p[0].x; x_c[0]++;
        y[0] = p[0].y; y_c[0]++;
      } else{
        if(x[0] == p[i].x){
          x_c[0]++;
        } else{
          x[1] = p[i].x;
          x_c[1]++;
        }

        if(y[0]==p[i].y){
          y_c[0]++;
        }else{
          y[1] = p[i].y;
          y_c[1]++;
        }
      }
  }

  printf("%d %d", x[COMPARE(x_c[0], x_c[1])], y[COMPARE(y_c[0], y_c[1])]);
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
