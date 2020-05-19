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

typedef struct __query{
  char type;
  int L;
  int R;
} query;

int subsweetness(char* arr, int L, int R){
  int i, ans = 0;
  for(i=L-1;i<R;i++){
    if((i-L+1) % 2 == 0) ans += (arr[i]*(i-L+2));
    else ans -= (arr[i]*(i-L+2));
    // printf("ans : %d\n", ans);
  }
  return ans;
}

void solve(int test_num){
  int i, j, N, Q, ans=0, count=0;
  char As[200000];
  query Qs;
  char temp;
  scanf("%d %d", &N, &Q);

  for(i=0;i<N;i++){
    scanf("%d", As+i);
  }

  scanf("%c", &temp);

  for(i=0;i<Q;i++){
    scanf("%c %d %d", &Qs.type, &Qs.L, &Qs.R);
    scanf("%c", &temp);
    if(Qs.type == 'U') As[Qs.L-1] = Qs.R;
    else{
      ans += subsweetness(As, Qs.L, Qs.R);
    }
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
