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

typedef char (*C2ARR51)[51];

int sort_key(const void* a, const void* b){
  int i=0;
  if(strlen(*(C2ARR51)a) != strlen(*(C2ARR51)b)){
    return strlen(*(C2ARR51)a) - strlen(*(C2ARR51)b);
  } else{
    
    while((*(C2ARR51)a)[i] == (*(C2ARR51)b)[i] && i< strlen(*(C2ARR51)b)-1){
      i++;
    }

    return (*(C2ARR51)a)[i] - (*(C2ARR51)b)[i];
  }
}

void solve(int test_num){
	int i, j, temp, N;
  char words[20000][51];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%s", words[i]);
  }

  qsort(words, N, sizeof(char)*51, sort_key);

  for(i=1;i<=N;i++){
    if(strcmp(words[i], words[i-1]))
      printf("%s\n", words[i-1]);
  }

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
