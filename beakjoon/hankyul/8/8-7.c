#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

int reverse_num(int num){
  int i, ans=0;
  for(i=0;i<3;i++){
    ans += ((num % 10) * pow(10, 2-i));
    num /= 10;
  }

  return ans;
}

void solve(int test_num){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    a = reverse_num(a); b = reverse_num(b);

    printf("%d", COMPARE(a, b));

    return;
}

int main(void){
  solve(0);
  return 0;
}
