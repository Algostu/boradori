#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COMPARE(X, Y) (X) > (Y) ? 0 : ((X) == (Y) ? 0 : 1)

#define SWAP(X, Y, T) T temp = (X); (X) = (Y); (Y) = temp;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

typedef struct __person{
  int num;
  int height;
  int weight;
} person;

void solve(int test_num){
  int i, j, k, N, temp, ans;
  person people[50];
  // get input N : target number
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d %d", &people[i].weight, &people[i].height);
    people[i].num = 1;
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(i==j) continue;
      if(people[i].weight < people[j].weight && people[i].height < people[j].height){
        people[i].num++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d ", people[i].num);
  }
  printf("\n");
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(0);
  // }

  solve(0);

	return 0;
}
