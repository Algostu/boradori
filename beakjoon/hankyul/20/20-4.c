#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int stack1[101];
int bound1 = 0;

void push1(int val){
  stack1[bound1++]=val;
}

int pop1(void){
  if(bound1 == 0) return -1;
  else return stack1[--bound1];
}

void solve(int test_num){
  int c, ans;
  char str[101];

  gets(str);

  while(strcmp(str, ".") != 0){
    ans = 0;
    for(c=0;c<strlen(str);c++) {
      if(ans == 1) break;
      if(str[c] == '[' || str[c]=='(') push1(str[c]);
      else if (str[c] ==']'){
        if(pop1()!='[') ans = 1;
      } else if (str[c] == ')'){
        if(pop1()!='(') ans = 1;
      }
    }
    if(ans == 1) printf("no\n");
    else if (bound1 != 0) printf("no\n");
    else printf("yes\n");
    bound1 = 0;
    gets(str);
  }

}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(i+1);
  // }

  solve(0);

	return 0;
}
