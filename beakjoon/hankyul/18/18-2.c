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

typedef struct __lecture{
  int s;
  int e;
} lecture;

int comp(const void * a, const void * b){
    int s1, s2, e1, e2;
    s1 = (*(lecture*)a).s;
    s2 = (*(lecture*)b).s;
    e1 = (*(lecture*)a).e;
    e2 = (*(lecture*)b).e;
    if(e1 != e2) return e1 - e2;
    else return s1 - s2;
}

void solve(int test_num){
  int i, N, ans = 0, end;
  lecture lects[10000];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d %d", &lects[i].s, &lects[i].e);
  }

  qsort(lects, N, sizeof(lecture), comp);

  end = lects[0].e;
  ans += 1;

  for(i=1;i<N;i++){
    if(lects[i].s < end) continue;
    ans+=1; end = lects[i].e;
  }

  printf("%d", ans);
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
