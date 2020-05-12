#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

void solve(int test_num){
    const char* words[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    char input[101];
    int i, size_t = 8, where=0, count = 0;

    scanf("%s", input);

    while(where < strlen(input)){
      printf("%d where : %d\n", count, where);
      for(i=0;i<size_t;i++){
          if(strncmp(input+where, words[i], strlen(words[i]))==0) {count++;}
      }
      where++;
    }
    printf("%d", count);
}s

int main(void){
  solve(0);
  return 0;
}
