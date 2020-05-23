#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void solve(int test_num){
  int x, y, i, j, distance, ans;
  int n;
  scanf("%d %d", &x, &y);

  distance = y - x;
  n = (int)ceil(sqrt(distance));
  if(n*n - distance < n) ans = 2*n - 1;
  else ans = 2*n - 2;
  printf("%d\n", ans);
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }
	return 0;
}
