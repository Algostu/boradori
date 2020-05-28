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

typedef struct __cloth{
  char type[21];
  int many;
} cloth;

void solve(int test_num){
  int i, j, ans=1, N, found, Types=0, memo[30], arr[30];
  cloth cloths[30];
  char name[21], type[21];

  for(i=0;i<30;i++){
    cloths[i].many = 0;
    cloths[i].type[0] = '\0';
  }

  scanf("%d", &N);

  for(i=0;i<N;i++){
    found = 0;
    scanf("%s %s", name, type);
    for(j=0;j<Types;j++){
      if(strlen(cloths[j].type) == strlen(type) && strcmp(cloths[j].type, type)==0){
        cloths[j].many++;
        found = 1;
      }
    }

    if(found == 0){
      strcpy(cloths[Types].type, type);
      cloths[Types++].many++;
    }
  }

  for(i=0;i<Types;i++){
    // printf("%s : %d\n", cloths[i].type, cloths[i].many);
    ans *= (cloths[i].many+1);
  }

  printf("%d\n", ans-1);

}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(i+1);
  }

  // solve(0);

	return 0;
}
