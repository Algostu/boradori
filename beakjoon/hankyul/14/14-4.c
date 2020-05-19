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

void solve(int test_num){
	int i, j, temp, smallest=100, N;
  int original[8001];
  int* count = &original[4000];
  int sum = 0, middle, index=0, most_frequent=0;
  int indeces[50], where = 0, min=4000, max = -4000, range;

  memset(original, 0, 8001*sizeof(int));

  scanf("%d", &N);

  middle = N/2+1;

  for(i=0;i<N;i++){
    scanf("%d", &temp);
    count[temp]++;
    sum += temp;
    if(temp < min) min = temp;
    if(temp > max) max = temp;
    if(most_frequent < count[temp]) most_frequent = count[temp];
  }

  // average
  printf("%d\n", (int)floor((double)sum/N + 0.5));

  // middle
  for(i=-4000;i<4001;i++){
    if(index + count[i] >= middle && index < middle) printf("%d\n", i);
    index += count[i];
    if(count[i] == most_frequent){
      indeces[where++] = i;
    }
  }

  // most_frequent
  if(where > 1) printf("%d\n", indeces[1]);
  else printf("%d\n", indeces[0]);

  // range
  printf("%d\n", max - min);

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
