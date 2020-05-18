#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

int* Eratos(int n){
  int i,j;
  int* arr;
  MALLOC(arr, sizeof(int) * n+1);
  arr[1] = 0;

  for(i=2;i<=n;i++){
    arr[i] = 1;
  }

  for(i=2;i*i<=n;i++){
    if(arr[i])
    for(j=i*i;j<=n;j+=i){
      arr[j]=0;
    }
  }
  return arr;
}

void solve(int test_num){
  int gold_part[2];
  int *primebool, primeArray[1300], count=0, n, i;
  primebool = Eratos(10000);
  for(i=1;i<10000;i++){
    if(primebool[i]) primeArray[count++] = i;
  }

  scanf("%d", &n);

  count=0;

  while(1){
    if(primebool[n - primeArray[count]]) {
      gold_part[0] = primeArray[count];
      gold_part[1] = n - primeArray[count];
    }
    if(primeArray[++count] > n / 2) break;
  }

  printf("%d %d\n", gold_part[0], gold_part[1]);
}

int main(){
  int i, N;
  scanf("%d", &N);
  for(i=0;i<N;i++){
      solve(0);
  }

  // solve(0);

	return 0;
}
