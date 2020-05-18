#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

void solve(int test_num){
    const char* words[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    char input[101];
    int i, size = 8, where=0, count = 0, found=0;

    scanf("%s", input);

    while(where < strlen(input)){
		found = 0;
	
      printf("%d where : %d\n", count, where);
      for(i=0;i<size;i++){
          if(strncmp(input+where, words[i], strlen(words[i]))==0) {
		  		
		  		count++;
				where+=strlen(words[i]);
				found = 1;
				break;
				
			}
      }
	  
	  if(found==0){
	  	where++;
		count++;		 
	  }
      
    }
    printf("%d\n", count);
}

int main(void){
  int i,t;
  scanf("%d", &t);
  for(i=0;i<t;i++){
  	solve(0);	
  }
 
  return 0;
}
