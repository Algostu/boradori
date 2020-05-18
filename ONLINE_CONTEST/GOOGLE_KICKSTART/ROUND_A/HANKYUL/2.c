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

typedef struct __poly{
  char name;
  char content[900][2];
  int size;
  char ups[26];
  int num_up;
  char downs[26];
  int num_down;
} poly;

void delete_from_list_poly(poly ** arr, int * size, poly * target){
  int i, found = 0;
  for(i=0;i<*size;i++){
    if(found == 0 && arr[i] == target){
      found = 1;
    } else if (found == 1){
      arr[i-1] = arr[i];
    }
  }
  (*size) -= 1;
}

void delete_from_list(char * arr, int * size, char target){
  int i, found = 0;
  for(i=0;i<*size;i++){
    if(found == 0 && arr[i] == target){
      found = 1;
    } else if (found == 1){
      arr[i-1] = arr[i];
    }
  }
  (*size) -= 1;
}

void solve(int test_num){
  int i, j, k, q, R, C, found=0, count=0, ans_count=0;
  char ans[27];
  char wall[30][31];
  poly alpha_poly[26];
  poly *polys[26];

  for(i=0;i<26;i++){
    alpha_poly[i].name = 'A'+i;
    alpha_poly[i].size = 0;
    alpha_poly[i].num_down = 0;
    alpha_poly[i].num_up = 0;
  }

  scanf("%d %d", &R, &C);

  for(i=0;i<R;i++){
    scanf("%s", wall[i]);
    for(j=0;j<C;j++){
      alpha_poly[wall[i][j] - 'A'].content[alpha_poly[wall[i][j] - 'A'].size][0] = j;
      alpha_poly[wall[i][j] - 'A'].content[alpha_poly[wall[i][j] - 'A'].size][1] = i;
      alpha_poly[wall[i][j] - 'A'].size++;
    }
  }

  for(i=0;i<26;i++){
    if(alpha_poly[i].size > 0){
      polys[count] = &alpha_poly[i];
      count++;
    }
  }

  // debug
  // printf("count : %d\n", count);
  //
  // for(i=0;i<count;i++){
  //   printf("%C===================\n", polys[i]->name);
  //   for(j=0;j<R;j++){
  //     for(k=0;k<C;k++){
  //       found = 0;
  //       for(q=0;q<polys[i]->size;q++){
  //         if(polys[i]->content[q][0] == k && polys[i]->content[q][1] == j){
  //           printf("%C", polys[i]->name);
  //           found = 1;
  //           break;
  //         }
  //       }
  //       if(found==0) printf(" ");
  //     }
  //     printf("\n");
  //   }
  // }

  int x, y;
  int up, down;
  // debug2 + Some algorithm
  for(i=0;i<count;i++){
    // printf("%C===================\n", polys[i]->name);
    for(j=0;j<polys[i]->size;j++){
      y = polys[i]->content[j][1];
      x = polys[i]->content[j][0];

      // add down
      if(y < R-1){
        found = 0;
        down = wall[y+1][x];
        if(down != polys[i]->name){
          for(k=0;k<polys[i]->num_down;k++){
            if(down == polys[i]->downs[k]){
              found = 1;
              break;
            }
          }
          if(found==0){
            polys[i]->downs[polys[i]->num_down++] = down;
          }
        }
      }


      // add up
      if(y > 0){
        found = 0;
        up = wall[y-1][x];
        if(up != polys[i]->name){
          for(k=0;k<polys[i]->num_up;k++){
            if(up == polys[i]->ups[k]){
              found = 1;
              break;
            }
          }
          if(found==0){
            polys[i]->ups[polys[i]->num_up++] = up;
          }
        }
      }
    }

    // debug3
    // printf("Ups : ");
    // for(j=0;j<polys[i]->num_up;j++){
    //   printf("%c ", polys[i]->ups[j]);
    // }
    // printf("\n");
    //
    // printf("Downs : ");
    // for(j=0;j<polys[i]->num_down;j++){
    //   printf("%c ", polys[i]->downs[j]);
    // }
    // printf("\n");

    // fail case
    for(j=0;j<polys[i]->num_up;j++){
      for(k=0;k<polys[i]->num_down;k++){
        if(polys[i]->ups[j] == polys[i]->downs[k]){
          printf("Case #%d: %d\n", test_num, -1);
          return;
        }
      }
    }
  }

  // sort by downs
  while(1){
    if(count < 1){
      break;
    }
    for(i=0;i<count;i++){
      if(polys[i]->num_down == 0){
        ans[ans_count++] = polys[i]->name;
        ans[ans_count] = '\0';

        //delete from down list by searching up list
        for(j=0;j<polys[i]->num_up;j++){
          for(k=0;k<count;k++){
            if(polys[i]->ups[j] == polys[k]->name)
              delete_from_list(polys[k]->downs, &polys[k]->num_down, polys[i]->ups[j]);
          }
        }

        // delete poly from poly list
        delete_from_list_poly(polys, &count, polys[i]);
      }
    }
  }
  printf("Case #%d: %s\n", test_num, ans);
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
