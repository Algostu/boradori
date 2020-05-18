#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int is_prime(int num){
  int i;
  if(num == 1) return 0;
  for(i=2;i<num;i++){
    if(num % (i) == 0) return 0;
  }
  return 1;
}

void solve(int test_num){
  int M, N, i, arr, min=10000, sum=0;
  scanf("%d", &M);
  scanf("%d", &N);
  for(i=M;i<=N;i++){
    if(is_prime(i)){
      sum += i;
      if(min > i) min = i;
    }
  }
  if(sum==0) printf("-1\n");
  else printf("%d\n%d\n", sum, min);
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
