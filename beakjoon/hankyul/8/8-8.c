#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

void solve(int test_num){
    char input[30];
    int ans=0, i;
    scanf("%s", input);

    for(i=0;i<strlen(input);i++){
      if(input[i] >= 'A' && input[i] <='O') ans += ((int)((input[i]-'A') / 3) + 3);
      else if(input[i] >= 'P' && input[i] <='S') ans += 8;
      else if(input[i] >= 'T' && input[i] <='V') ans += 9;
      else ans += 10;
    }

    printf("%d", ans);

    return;
}

int main(void){
  solve(0);
  return 0;
}
