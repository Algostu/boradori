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

int self_pow(int base, int exp){
  int i, ans = base;
  for(i=1;i<exp;i++){
    ans *= base;
  }
  return ans;
}

int six_digit_num(int n){
	int i;
	int ans = 0;

  for(i=2;i<n;i++){
    if(self_pow(10, i) >= n){
      i--;
      break;
    }
  }

  //debug
  // printf("i : %d\n", i);

	while(1){
		if(n < 10) break;
    if(ans >= 3){
      ans++;
      n %= (self_pow(10,i--));
    } else{
      if((n/self_pow(10,i)) == 6) ans++;
      else ans = 0;

      //debug
      // printf("(%d/(int)self_pow(10,%d)) : %d\n", n, i, (n/self_pow(10,i)));
      // printf("%d % ((int)self_pow(10,%d--)) : %d\n", n, i, n % (self_pow(10,i)));
      // printf("((int)self_pow(10,i)) : %d\n", (self_pow(10,i)));

      n %= (self_pow(10,i--));
    }
	}

	if(ans >= 3) {
    ans++;
    return ans - 3;
  }
	return 0;
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

      // debug
      // printf("where is ? %d : %d\n", ans, six_digit_num(ans));

			temp = self_pow(10, six_digit_num(ans));

			for(j=0;j<temp;j++){
				if(i+j+1 == N) {
          // debug
					// printf("i : %d j : %d N : %d\n", i,j,N);
					break;
				}
			}
			if(j != temp){
        ans -= (ans%temp);
        ans += j;
        i += j;
      } else{
        i += (j-1);
      }

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
