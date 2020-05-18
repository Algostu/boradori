#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int six_digit_num(int n){
	int i;
	int ans = 0; n /= 1000;
	while(1){
		if(n < 10) break; 
		if(n % 10 == 6) ans++;
		else ans = 0;
		n /= 10; 
	}
	
	if(n == 6) ans++;
	
	return ans;
}

void solve(int test_num){
	int i=1, j, N, ans = 666, temp;
	scanf("%d", &N);
	
	while(i<N){
		temp = 0;
		if(six_digit_num(ans+1000) == 0){
			ans += 1000;
		}	
		else{
			ans += 1000;
			temp = pow(10, six_digit_num(ans));
			ans -= (ans%temp);
			
			for(j=0;j<temp;j++){
				if(i+j+1 == N) {
					printf("%d", i);
					break;	
				}
			}
			i += j;
			if(j == temp) {ans += }
			else ans += j;
			
		}
		i++;
	}
	
	printf("%d\n", ans);
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve();
  // }

  	solve(0);

	return 0;
}
