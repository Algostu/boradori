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
  int N, i, arr[100], count=0;
  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", arr+i);
    if(is_prime(arr[i])) count++;
  }

  printf("%d", count);
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
