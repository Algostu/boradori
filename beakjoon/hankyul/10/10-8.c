#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 0 : ((X) == (Y) ? 0 : 1)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

typedef struct __point{
  double x;
  double y;
} point;

double distance(point p1, point p2){
  double ans;
  ans = sqrt(abs(pow(p1.x - p2.x, 2)) + abs(pow(p1.y - p2.y, 2)));
  return ans;
}

void solve(int test_num){
  point p1, p2;
  int r1, r2;
  double dist;

  scanf("%lf %lf %d %lf %lf %d", &p1.x, &p1.y, &r1, &p2.x, &p2.y, &r2);

  if(COMPARE(r1, r2)) {SWAP(r1, r2, int);}

  dist = distance(p1, p2);
  
  if(dist == 0){
    if(r1 == r2) printf("-1\n");
    else printf("0\n");
  } else if(dist <= r1) {
    if(dist + r2 < r1){
    printf("0\n");
  } else if(dist + r2 == r1){
    printf("1\n");
  } else if(dist + r2 > r1){
    printf("2\n");
  }
  } else {
    if(dist < r1 + r2){
    printf("2\n");
  } else if(dist == r1+r2){
    printf("1\n");
  } else {
    printf("0\n");
  }
  }
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }

  // solve(0);

	return 0;
}
