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

int digit_sum(int num){
  int ans=num;
  while(1){
    if(num<10){
      break;
    }

    ans += (num%10);
    num /= 10;
  }

  ans += num;
  return ans;
}

int constructor(int num){
  int i;
  if(num == 1) return 0;
  for(i=num/2;i<num;i++){
    if(digit_sum(i) == num) return i;
  }
  return 0;
}
void solve(int test_num){
  int i, j, k, N, temp, ans;

  // get input N : target number
  scanf("%d", &N);

  ans = constructor(N);

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
