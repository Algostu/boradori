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

int queue[1000];
int front;
int rear;

void push(int val){
	queue[rear++] = val;
	if(rear==1000) rear = 0;
}

int pop(void){
	int ans;
	if(rear == front) return -1;
	ans = queue[front++];
	if(front==1000) front = 0; 
	return ans;
}

void solve(int test_num){
	front = rear = 0;
	int i,j,k, temp;
	int N, M, count[10]={0};
	int target_priority, ans = 0, target=0, cur=0, total=0;
	
	scanf("%d %d", &N, &M);
	
	for(i=0;i<N;i++){
		scanf("%d", &queue[i]);
		count[queue[i]]++;
	}
	
	rear = N;
	target_priority = queue[M];
	
	for(i=0;i<N;i++){
		if(queue[i]==target_priority){
			if(i==M){
				target = total;
			}
			total++;
		}
	}
	
	for(i=9;i>target_priority;i--){
		if(count[i]){
			while(1){
				temp = pop();
				if(temp == i) { 
					count[i]--;
					ans ++;
					if(!count[i]) break;
				}
				else { 
					if(temp == target_priority){
						cur = (cur+1) % total;
					}
					push(temp); 
				}
			}
		}
		
	}
	// printf("ans : %d target : %d, cur : %d\n", ans, target, cur);
	if(target>=cur) printf("%d\n", ans + target - cur + 1);
	else printf("%d\n", ans + total - (cur - target) + 1); 

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

