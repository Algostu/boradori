#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve(int test_num){
	 int ans = 1, where=0;
   int A, B, V;
   scanf("%d %d %d", &A, &B, &V);

   if((V-A) % (A-B) == 0) printf("%d", 1+(V-A)/(A-B));
   else printf("%d", 2+(V-A)/(A-B));
}

int main(){
	solve(0);

	return 0;
}
