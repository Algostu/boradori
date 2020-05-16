#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int house(int k, int n){
  int i, ans=0;
  if(k==0){
    return n;
  }

  for(i=0;i<n;i++){
    ans += house(k-1, i+1);
  }
  return ans;
}

void solve(int test_num){
  int k, n;
  scanf("%d", &k); scanf("%d", &n);

  printf("%d\n", house(k, n));
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }
	return 0;
}
