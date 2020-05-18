#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve(int test_num){
  int H, W, N;
  scanf("%d %d %d", &H, &W, &N);

  if(N % H == 0) printf("%d\n", H * 100 + N / H);
  else printf("%d\n", (N % H) * 100 + N / H +1);
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }
	return 0;
}
