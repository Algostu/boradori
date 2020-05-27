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

void char_int(int * i, char * a){
  int ans=0, j, base = 1;
  for(j=strlen(a)-1; j>=0;j--){
    ans += base * (a[j] + (0-'0'));
    base *= 10;
  }
  *i = ans;
}

void solve(int test_num){
  int i, N=0, index = 0, A[50], branch = -1;
  char input[51], original[51];
  char * temp;

  scanf("%s", input);

  strcpy(original, input);

  temp = strtok(input, "+-");

  if(temp == NULL){
    fprintf(stderr, "strtok error!\n");
    exit(EXIT_FAILURE);
  }

  char_int(A+N, temp);

  N+=1;
  index += (strlen(temp));

  if(branch == -1 && original[index] == '-') branch = N;

  while(temp = strtok(NULL, "+-")){
    char_int(A+N, temp);

    N+=1;
    index += (strlen(temp)+1);

    if(branch == -1 && original[index] == '-') branch = N;
  }
  // printf("branch : %d\n", branch);
  int left=0, right=0;

  if(branch != -1)
    for(i=0;i<N;i++){
      if(i < branch) left += A[i];
      else right += A[i];
    }
  else
    for(i=0;i<N;i++){
      left += A[i];
    }

  printf("%d\n", left-right);
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
