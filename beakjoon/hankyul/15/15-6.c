#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? 1 : ((X) == (Y) ? 1 : 0)

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

typedef int (*sdoqu)[9];
typedef struct __candidate{
  int state;
  int r;
  int c;
  int available;
  int nums[10];
} candidate;

int fill_sdoqu(sdoqu arr, candidate* list, int index, int n, int remaining){
  int i, j, r, c, count = 0, remove_list[20], remove_count=0, min=10, min_index, nums[10] = {0};
  candidate* temp[20];

  // debug
  // printf("remaing : %d\n", remaining);

  // final end
  if(remaining == 0){
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
    return 0;
  }

  // wrong end
  else if (list[index].available == 0){
    return -1;
  }

  // recall
  else {
    r = list[index].r; c = list[index].c;
    list[index].state = 0;

    // printf("available : %d\n", list[index].available);

    for(j=0;j<n;j++){
      if(list[j].r == r || list[j].c == c){
        temp[count++] = &list[j];
      } else if (list[j].r/3 == r/3 && list[j].c/3 == c/3){
        temp[count++] = &list[j];
      }
    }

    for(i=1;i<10;i++){
      if(list[index].nums[i] == 1){
        remove_count = 0;
        arr[r][c] = i;

        for(j=0;j<count;j++){
          if(temp[j]->nums[i] == 1){
            temp[j]->nums[i] = 0;
            temp[j]->available--;
            remove_list[remove_count++] = j;
          }
        }

        for(j=0;j<n;j++){
          if(list[j].state==1 && min > list[j].available){
            min = list[j].available;
            min_index = j;
          }
        }

        if (fill_sdoqu(arr, list, min_index, n, remaining-1) == 0) return 0;

        for(j=0;j<remove_count;j++){
          temp[remove_list[j]]->nums[i] = 1;
          temp[remove_list[j]]->available++;
        }
      }
    }
    list[index].state = 1;
    return -1;
  }

}

void solve(int test_num){
	int i,j, k, w, r, c, min = 10, min_index= 0;
  int arr[9][9], blank = 0;
  int nums[10];
  candidate list[91];

  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      scanf("%d", &arr[i][j]);
    }
  }

	for(i=0;i<9;i++){
    for(j=0;j<9;j++){

      if(arr[i][j] == 0){
        r = i; c = j;

        // nums 초기화
        for(k=0;k<10;k++) nums[k] = 0;

        // 가로 세로줄에서 나타난 숫자 제외
        for(k=0;k<9;k++){
          nums[arr[k][c]]++;
          nums[arr[r][k]]++;
        }

        // 포함된 3*3 박스에서 나타난 숫자 제외
        for(k=(r/3)*3;k<(r/3)*3+3;k++){
          for(w=(c/3)*3;w<(c/3)*3+3;w++){
            nums[arr[k][w]]++;
          }
        }

        list[blank].r = i;
        list[blank].c = j;
        list[blank].available = 0;
        list[blank].state = 1;

        for(k=1;k<10;k++){
          if(nums[k] == 0){
            list[blank].nums[k] = 1;
            list[blank].available+=1;
          } else list[blank].nums[k] = 0;
        }

        if(list[blank].available < min) {min=list[blank].available; min_index = blank;}
        blank++;

      }
    }
  }

  //debug
  // for(i=0;i<blank;i++){
  //   printf("%d, %d, available = %d==============\n", list[i].r, list[i].c, list[i].available);
  //   for(j=1;j<10;j++) if(list[i].nums[j]==1) printf("%d ", j);
  //   printf("\n");
  // }

	fill_sdoqu(arr, list, min_index, blank, blank);

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
