#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

void solve(int test_num){
	int a, b, c, temp;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		
		if(a == 0 && b == 0 && c == 0) break;

		if(COMPARE(a,b)) {SWAP(a, b, int)}

		if(COMPARE(b, c)) {SWAP(b, c, int)}

		if((a*a + b*b) == c*c) printf("right\n");
		else printf("wrong\n");
	}
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